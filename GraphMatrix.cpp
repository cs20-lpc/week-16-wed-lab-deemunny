#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV,0,type) {
    // TODO
    adjMatrix = new bool*[verts];
    for (int i = 0; i < verts; ++i) adjMatrix[i] = new bool[verts]{};
}

GraphMatrix::~GraphMatrix() {
    // TODO
    for (int i = 0; i < verts; ++i) delete[] adjMatrix[i];
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO
    if (i < 0 || i >= verts || j < 0 || j >= verts) {
        cout << "Value out of bounds. ";
        return false;
    } 
    return adjMatrix[i][j];
}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < verts; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < verts; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < verts; i++) {
        os << i << " | ";
        for (int j = 0; j < verts; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO
    if (i < 0 || i >= verts || j < 0 || j >= verts) {
        cout << "Value out of bounds. " << endl;
        return;
    } 

    if (i == j) {
        cout << "Self loops disallowed at this time" << endl;
        return;
    }

    if (adjMatrix[i][j]) --edges;
    else ++edges;

    adjMatrix[i][j] = !adjMatrix[i][j];
    

    // if (graphType == UNDIRECTED) adjMatrix[j][i] = !adjMatrix[j][i];
    if (graphType == UNDIRECTED) adjMatrix[j][i] = adjMatrix[i][j];
    
}
