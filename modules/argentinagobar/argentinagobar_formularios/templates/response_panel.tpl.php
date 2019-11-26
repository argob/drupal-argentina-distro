<div class="panel panel-default panel-disabled m-b-2">
  <div class="panel-body">
    <h2 class="table_title m-b-2"><?php print $titulo ?></h2>
    <?php $columns = array_chunk($data, ceil(count($data) / 2 )); ?>
    <?php foreach ($columns as $column){ ?>
    <div class="col-md-6">
      <?php foreach ($column as $item){ ?>
      <label class="control-label"><?php print $item['label']; ?></label>
      <p><?php print $item['value']; ?></p>
      <?php } ?>
    </div>
    <?php } ?>
  </div>
</div>