#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main(int argc, char **argv) 
{
  // exploit namespaces to shorten code
  using namespace boost::numeric::ublas;
  using std::cout; 
  using std::endl;
   int xmin = argv[1];
   int xmax = argv[2];
   int xlen = argv[3]; 
   int ymin = argv[4];
   int ymax = argv[5];
   int ylen = argv[6]; 
   float dx = (xmax-xmin)/(xlen-1);
   float dy = (ymax-ymin)/(ylen-1);    
   
  // declare three 3x3 matrices of complex<long double> elements
  matrix<std::complex<long double> > m(j, k);

  // iterate over 3x3 matrix entries
  // r : row index
  // c : column index
  for (unsigned r = 0; r < m.size1(); r++) {
    for (unsigned c = 0; c < m.size2(); c++) {
      // enumerated matrix entries
      m(r,c) = (xmin + r*dx) + (ymin + c*dy);
    }
  }

  // print to screen as demonstration
  cout << "m:" << endl;
  cout << m << endl;

}
