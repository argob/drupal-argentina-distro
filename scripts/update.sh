#!/bin/bash
set -e

#
# Build the distribution using the same process used on Drupal.org
#
# Usage: scripts/build.sh [-y] <destination> from the profile main directory.
#

confirm () {
  read -r -p "${1:-Are you sure? [Y/n]} " response
  case $response in
    [yY][eE][sS]|[yY])
      true
      ;;
    *)
      false
      ;;
  esac
}

# Figure out directory real path.
realpath () {
  TARGET_FILE=$1

  cd `dirname $TARGET_FILE`
  TARGET_FILE=`basename $TARGET_FILE`

  while [ -L "$TARGET_FILE" ]
  do
    TARGET_FILE=`readlink $TARGET_FILE`
    cd `dirname $TARGET_FILE`
    TARGET_FILE=`basename $TARGET_FILE`
  done

  PHYS_DIR=`pwd -P`
  RESULT=$PHYS_DIR/$TARGET_FILE
  echo $RESULT
}

usage() {
  echo "Usage: build.sh [-y] <DESTINATION_PATH>" >&2
  echo "Use -y to skip deletion confirmation" >&2
  exit 1
}

DESTINATION=./
DESTINATION2=../../
ASK=true

while getopts ":y" opt; do
  case $opt in
    y)
      DESTINATION=$2
      ASK=false
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      usage
      ;;
  esac
done

if [ "x$DESTINATION" == "x" ]; then
  usage
fi

if [ ! -f drupal-org.make ]; then
  echo "[error] Run this script from the distribution base path."
  exit 1
fi

# Build the profile.
echo "Updating profile..."
drush -v make --working-copy --no-core --contrib-destination="." drupal-org.make tmp
cp -rvu tmp/. .
rm -rf tmp
echo "include external configs in settings.php"
echo "done"