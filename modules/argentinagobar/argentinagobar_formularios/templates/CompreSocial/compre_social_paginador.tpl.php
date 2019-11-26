<nav class="text-center">
  <ul class="pagination">
    <?php if($total > $per_page): ?>
    <li>
      <a 
        class="<?= ($current_page == 1) ? 'btn disabled' : '' ?>" 
        href="<?= (strpos($current_url, '?') !== false) ? $current_url.'&' : $current_url.'?' ?><?= 'page='.($current_page-1).'&limit='.$per_page ?>" 
        aria-label="Previous"
      >
        <span aria-hidden="true">«</span>
      </a>
    </li>

      <?php for ($i = $start;  $i <= $end; $i++) : ?>

        <li class="<?= ($current_page == $i) ? 'active' : '' ?>">
          <a href="<?= (strpos($current_url, '?') !== false) ? $current_url.'&' : $current_url.'?' ?><?= 'page='.$i.'&limit='.$per_page ?>"><?= $i ?></a>
        </li>

      <?php endfor; ?>

    <li>
      <a 
        class="<?= ($current_page == $last_page) ? 'btn disabled' : '' ?>" 
        href="<?= (strpos($current_url, '?') !== false) ? $current_url.'&' : $current_url.'?' ?><?= 'page='.($current_page+1).'&limit='.$per_page ?>" 
        aria-label="Next"
      >
        <span aria-hidden="true">»</span>
      </a>
    </li>
   
    <?php endif; ?>
  </ul>
</nav>