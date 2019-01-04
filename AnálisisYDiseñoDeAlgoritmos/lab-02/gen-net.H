

auto create_random_net(const size_t num_nodes, const double prob,
		       const long min_w, const  long max_w,
		       const unsigned long seed)
{
  auto r = gsl_rng_alloc (gsl_rng_mt19937);
  gsl_rng_set(r, seed % gsl_rng_max(r));

  auto ret_val = Random_Graph<SocialNet> (seed) (num_nodes, prob);

  unsigned long id = 0;
  ret_val.for_each_node([&id, r] (auto p)
			{
			  auto & f = p->get_info();
			  f.id = id++;
			  f.color = gsl_rng_uniform_int(r, 255) + 1;
			});

  ret_val.for_each_arc([&min_w, &max_w, r] (auto a)
		       {
			 auto & f = a->get_info();
			 f.color = gsl_rng_uniform_int(r, 255) + 1;
			 int sz = max_w - min_w + 1;
			 f.cost = gsl_rng_uniform_int(r, sz) + min_w;
		       });			 
  gsl_rng_free(r);

  return ret_val;
}
