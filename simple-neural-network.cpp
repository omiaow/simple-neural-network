#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> sigmoid(vector<vector<double>> matrix) {
  vector<vector<double>> result;
  for (int i=0; i<matrix.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix[i].size(); j++) {
      row.push_back(1 / (1 + exp(-matrix[i][j])));
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> derivative_sigmoid(vector<vector<double>> matrix) {
  vector<vector<double>> result;
  for (int i=0; i<matrix.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix[i].size(); j++) {
      row.push_back(matrix[i][j] * (1 - matrix[i][j]));
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> dot_product(vector<vector<double>> matrix1, vector<vector<double>> matrix2) {
  vector<vector<double>> result;
  for (int i=0; i<matrix1.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix2[0].size(); j++) {
      double sum = 0;
      for (int k=0; k<matrix1[i].size(); k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      row.push_back(sum);
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> transpose(vector<vector<double>> matrix) {
  vector<vector<double>> result;
  for (int i=0; i<matrix.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix[i].size(); j++) {
      row.push_back(matrix[j][i]);
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> multiplication(vector<vector<double>> matrix1, vector<vector<double>> matrix2) {
  vector<vector<double>> result;
  for (int i=0; i<matrix1.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix1[i].size(); j++) {
      row.push_back(matrix1[i][j] * matrix2[i][j]);
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> addition(vector<vector<double>> matrix1, vector<vector<double>> matrix2) {
  vector<vector<double>> result;
  for (int i=0; i<matrix1.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix1[i].size(); j++) {
      row.push_back(matrix1[i][j] + matrix2[i][j]);
    }
    result.push_back(row);
  }
  return result;
}

vector<vector<double>> subtraction(vector<vector<double>> matrix1, vector<vector<double>> matrix2) {
  vector<vector<double>> result;
  for (int i=0; i<matrix1.size(); i++) {
    vector<double> row;
    for (int j=0; j<matrix1[i].size(); j++) {
      row.push_back(matrix1[i][j] - matrix2[i][j]);
    }
    result.push_back(row);
  }
  return result;
}

double random(double min, double max) {
    double coeficiente = (double)rand() / RAND_MAX;
    return min + coeficiente * (max - min);
}

void print(vector<vector<double>> matrix) {
  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[i].size(); j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}


int main(){
  vector<vector<double>> inputs {{0, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 1}};

  vector<vector<double>> outputs {{0}, {0}, {1}, {1}};

  vector<vector<double>> synaptics;

  for (int i=0; i<inputs[0].size(); i++) {
    vector<double> value;
    value.push_back(random(-1, 1));
    synaptics.push_back(value);
  }

  int training_number = 20000;

  vector<vector<double>> learned_output;

  for (int i=0; i<training_number; i++) {

    vector<vector<double>> input_layer = inputs;
    learned_output = sigmoid(dot_product(input_layer, synaptics));

    vector<vector<double>> error = subtraction(outputs, learned_output);

    vector<vector<double>> delta = multiplication(error, derivative_sigmoid(learned_output));

    synaptics = addition(synaptics, dot_product(transpose(input_layer), delta));
  }

  cout<<"output values after trainings"<<endl;
  print(learned_output);


  cout<<"output value of new input [1, 0, 0]"<<endl;
  vector<vector<double>> new_input {{1, 0, 0}};
  vector<vector<double>> new_output = sigmoid(dot_product(new_input, synaptics));
  print(new_output);

  return 0;
}

