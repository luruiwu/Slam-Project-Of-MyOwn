#ifndef __GRAPH_OPTIMIZE_H_
#define __GRAPH_OPTIMIZE_H_

#include <iostream>
#include <cmath>

#include "vertexSE2.h"
#include "edgeSE2.h"

#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/block_solver.h"
#include "g2o/core/factory.h"
#include "g2o/core/optimization_algorithm_factory.h"
#include "g2o/core/optimization_algorithm_gauss_newton.h"
#include "g2o/solvers/eigen/linear_solver_eigen.h"

namespace slam{
	
namespace optimizer{

class GraphOptimize
{
	using SlamBlockSolver = g2o::BlockSolver< g2o::BlockSolverTraits<-1, -1> >;
	using SlamLinearSolver = g2o::LinearSolverEigen<SlamBlockSolver::PoseMatrixType>;

public:
	GraphOptimize();
	~GraphOptimize();

	void createOptimizer();
	
	void addVertex( const Eigen::Vector3f &pose, const int id );
	
	void addEdge( const Eigen::Vector3f &delta );

	int execuateGraphOptimization();
	
	void getOptimizedResults();
private:
	g2o::SparseOptimizer optimizer; // allocating the optimizer
	
	int edgeCount = 0;
};

}

}


#endif
