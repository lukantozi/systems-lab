atomic_int x = 0;

x += 5; // sequential consistency, the default

atomic_fetch_add(&x, 5); // sequential consistency, the default

atomic_fetch_add_explicit(&x, 5, memory_order_seq_cst);

atomic_fetch_add_explicit(&x, 5, memory_order_acq_rel);
