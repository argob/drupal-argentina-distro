<?php $parametros = $url['parametros']; ?>

<nav class="text-center">
    <ul class="pagination">
<?php $anteriorIsDisabled = isset($anterior['isDisabled']) ? $anterior['isDisabled'] : "" ?>

      <?php $parametros['offset'] = $anterior['valor']; ?>

        <?php $urlAnterior = $anteriorIsDisabled ? '#' : base_path() . drupal_get_path_alias() . '?' . http_build_query($parametros); ?>

        <li class="page-item <?php if ($anteriorIsDisabled): print 'disabled'; endif; ?>">
            <a class="page-link" href="<?= $urlAnterior ?>" aria-label="Anterior">
                <span aria-hidden="true">&laquo;</span>
                <span class="sr-only">Anterior</span>
            </a>
        </li>

        <?php for($i = $items['anteriores']['desde']; $i < $items['anteriores']['hasta']; $i++): ?>

            <?php $parametros['offset'] = $i; ?>
            <li class="page-item">
                <a class="page-link" href="<?= $url['base'] . '?' . http_build_query($parametros) ?>">
                  <?= $i ?>
                </a>
            </li>

        <?php endfor; ?>

        <li class="page-item active">
          <span class="page-link">
            <?= $items['actual'] ?>
            <span class="sr-only">(Actual)</span>
          </span>
        </li>

      <?php for($i = $items['siguientes']['desde'] + 1; $i <= $items['siguientes']['hasta']; $i++): ?>

        <?php $parametros['offset'] = $i; ?>

          <li class="page-item">
              <a class="page-link" href="<?= $url['base'] . '?' . http_build_query($parametros) ?>">
                <?= $i ?>
              </a>
          </li>

      <?php endfor; ?>

      <?php $siguienteIsDisabled = isset($siguiente['isDisabled']) ? $siguiente['isDisabled'] : "" ?>

      <?php $parametros['offset'] = $siguiente['valor']; ?>

        <?php $urlSiguiente = $siguienteIsDisabled ? '#' : base_path() . drupal_get_path_alias() . '?' . http_build_query($parametros); ?>

        <li class="page-item <?php if ($siguienteIsDisabled): print 'disabled'; endif; ?>">
            <a class="page-link" href="<?= $urlSiguiente ?>" aria-label="Siguiente">
                <span aria-hidden="true">&raquo;</span>
                <span class="sr-only">Siguiente</span>
            </a>
        </li>

    </ul>
</nav>
