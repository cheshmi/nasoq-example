//
// Created by kazem on 2022-08-10.
//

// other includes omitted ....
#include <iostream>
#include "nasoq/eigen_interface/include/nasoq/nasoq_eigen.h"

void nasoqTest() {
    double pert = 1e-9;
    std::vector<Eigen::Triplet<double>> HList = {Eigen::Triplet<double>(0,0,1),
                                            Eigen::Triplet<double>(1,1,1),
                                            Eigen::Triplet<double>(2,2,1),
                                            Eigen::Triplet<double>(3,3,pert),
                                            Eigen::Triplet<double>(4,4,pert),
                                            Eigen::Triplet<double>(5,5,pert)
                                                    };
    Eigen::SparseMatrix<double,Eigen::ColMajor,int> H(6,6);
    H.setFromTriplets(HList.begin(), HList.end());

    std::vector<Eigen::Triplet<double>> AList = {Eigen::Triplet<double>(0,0,1),
                                            Eigen::Triplet<double>(0,3,-1),
                                            Eigen::Triplet<double>(0,5,-1),
                                            Eigen::Triplet<double>(1,1,1),
                                            Eigen::Triplet<double>(1,4,-1),
                                            Eigen::Triplet<double>(1,3,-1),
                                            Eigen::Triplet<double>(2,2,1),
                                            Eigen::Triplet<double>(2,5,-1),
                                            Eigen::Triplet<double>(2,4,-1)};
    Eigen::SparseMatrix<double,Eigen::ColMajor,int> A(3,6);
    A.setFromTriplets(AList.begin(), AList.end());

    std::vector<Eigen::Triplet<double>> CList = {Eigen::Triplet<double>(0,0,1),
                                            Eigen::Triplet<double>(1,1,1),
                                            Eigen::Triplet<double>(2,2,1),
                                            Eigen::Triplet<double>(3,0,-1),
                                            Eigen::Triplet<double>(6,0,1),
                                            Eigen::Triplet<double>(4,1,-1),
                                            Eigen::Triplet<double>(7,1,1),
                                            Eigen::Triplet<double>(5,2,-1),
                                            Eigen::Triplet<double>(8,2,1),
                                            Eigen::Triplet<double>(9,0,-1),
                                            Eigen::Triplet<double>(9,1,1),
                                            Eigen::Triplet<double>(9,2,1),
                                            Eigen::Triplet<double>(12,0,1),
                                            Eigen::Triplet<double>(12,1,-1),
                                            Eigen::Triplet<double>(12,2,-1),
                                            Eigen::Triplet<double>(10,1,-1),
                                            Eigen::Triplet<double>(10,2,1),
                                            Eigen::Triplet<double>(10,0,1),
                                            Eigen::Triplet<double>(13,1,1),
                                            Eigen::Triplet<double>(13,2,-1),
                                            Eigen::Triplet<double>(13,0,-1),
                                            Eigen::Triplet<double>(11,2,-1),
                                            Eigen::Triplet<double>(11,0,1),
                                            Eigen::Triplet<double>(11,1,1),
                                            Eigen::Triplet<double>(14,2,1),
                                            Eigen::Triplet<double>(14,0,-1),
                                            Eigen::Triplet<double>(14,1,-1)};
    Eigen::SparseMatrix<double,Eigen::ColMajor,int> C(15,6);
    C.setFromTriplets(CList.begin(), CList.end());

    Eigen::VectorXd q(6);
    q << -1.5708,-0.785398,-0.785398,0,0,0;

    Eigen::VectorXd b(3);
    b << 1.5708,0.785398,0.785398;
    Eigen::VectorXd d(15);
    d << -3.14159,-3.14159,-3.14159,0,0,0,6.28319,6.28319,6.28319,9.42478,9.42478,9.42478,3.14159,3.14159,3.14159;

    nasoq::QPSettings *qs = NULL;
    Eigen::VectorXd x,y,z;
    int status = nasoq::quadprog(H,q,A,b,C,d,x,y,z,qs);

    std::cout<<status;
    std::cout<<"Primal variables: ";
    for (int i = 0; i < H.rows(); ++i) {
        std::cout<<x[i]<<",";
    }

    // expected z = {1.6,0,0,0}
    std::cout<<"\nDual variables: ";
    for (int i = 0; i < A.rows(); ++i) {
        std::cout<<y[i]<<",";
    }
    for (int i = 0; i < C.rows(); ++i) {
        std::cout<<z[i]<<",";
    }

}

int main(int argc, char *argv[]){
    nasoqTest();
    return 1;
}
