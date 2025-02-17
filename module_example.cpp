#include <Rcpp.h>
using namespace Rcpp;

class Uniform {
public:
  Uniform(double min_, double max_) :
  min(min_), max(max_) {}
  
  NumericVector draw(int n) {
    RNGScope scope;
    return runif(n, min, max);
  }

  double min, max;
};

RCPP_MODULE(unif_module) {
  class_<Uniform>("Uniform")
  .constructor<double,double>()
  .field("min", &Uniform::min, "minimum value")
  .field("max", &Uniform::max, "maximum value")
  .method("draw", &Uniform::draw)
  ;
}
