#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>

int main(int argc, char **argv) 
{
  // exploit namespaces to shorten code
  using namespace boost::numeric::ublas;
  using std::cout; 
  using std::endl;
  int xmin = atoi(argv[1]);
  int xmax = atoi(argv[2]);
  int xlen = atoi(argv[3]);
  int ymin = atoi(argv[4]);
  int ymax = atoi(argv[5]);
  int ylen = atoi(argv[6]);
  int dx = (xmax-xmin)/(xlen-1);
  int dy = (ymax-ymin)/(ylen-1);    
   
  // declare three 3x3 matrices of complex<long double> elements
  matrix<std::complex<long double> > m(xlen, ylen);

  // iterate over 3x3 matrix entries
  // r : row index
  // c : column index
  for (unsigned r = 0; r < m.size1(); r++) {
    for (unsigned c = 0; c < m.size1(); c++) {
      // enumerated matrix entries

      m(r,c) = (xmin + r*dx) + ((ymin + c * dy) * std::complex<long double>(0,1));
    }
  }

  // print to screen as demonstration
    
  for (unsigned int i=0; i<xlen; i++) {
        for (unsigned int j=0; j<ylen; j++) {
            std::cout << m(i,j) << "\t";
        }
        std::cout << std::endl;
    }
}
