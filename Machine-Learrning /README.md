# Machine Learning

Machine Learning (ML) in C++ is a powerful combination for building high-performance applications due to C++’s efficiency, control over memory, and speed. While languages like Python are more popular for ML because of the vast ecosystem of libraries like TensorFlow, PyTorch, and scikit-learn, C++ is often used in production systems where performance is critical, or where the integration with low-level systems is required.

Here's a high-level introduction to Machine Learning using C++:

### 1. **Basics of Machine Learning**
Machine Learning is a field of artificial intelligence that focuses on building systems that learn from data and improve their performance without being explicitly programmed. The most common tasks in ML include:

- **Supervised Learning**: Learning from labeled data (e.g., classification, regression).
- **Unsupervised Learning**: Learning from unlabeled data (e.g., clustering).
- **Reinforcement Learning**: Learning through interaction with an environment to maximize some notion of cumulative reward.

### 2. **Why Use C++ for Machine Learning?**
- **Performance**: C++ offers fine-grained control over memory and performance, making it ideal for deploying large-scale machine learning models in production environments.
- **Embedded Systems**: C++ is commonly used in environments where you need to integrate ML with hardware or systems with limited resources.
- **Control**: C++ provides more control over optimization and hardware acceleration, which is crucial for high-performance applications such as real-time data processing or gaming AI.

### 3. **Core Libraries and Tools in C++**
To get started with machine learning in C++, you don’t need to write everything from scratch. Here are some popular libraries that provide algorithms and utilities for ML:

- **MLPack**: A fast, flexible C++ library for machine learning. It provides a wide variety of algorithms, such as classification, regression, clustering, and more.
- **Dlib**: A modern C++ toolkit that contains machine learning algorithms and tools for creating complex software.
- **Shark**: Another powerful library for ML in C++ that supports many classical ML algorithms like linear regression, k-means clustering, and neural networks.
- **Eigen**: A C++ template library for linear algebra. It is widely used in ML for efficient matrix operations.
- **TensorFlow C++ API**: TensorFlow also has a C++ API, allowing you to build and run models with the performance benefits of C++.

### 4. **Getting Started: Example of a Basic Machine Learning Algorithm**

Let’s walk through a basic example of implementing linear regression in C++. Linear regression is a supervised learning algorithm used to predict continuous values.

#### Simple Linear Regression in C++

```cpp
#include <iostream>
#include <vector>
#include <cmath>

class LinearRegression {
public:
    LinearRegression(double lr, int iterations) : learning_rate(lr), n_iterations(iterations) {}

    void fit(const std::vector<double>& X, const std::vector<double>& y) {
        int m = X.size();
        double b0 = 0, b1 = 0;  // Initialize parameters

        for (int i = 0; i < n_iterations; ++i) {
            double gradient_b0 = 0;
            double gradient_b1 = 0;

            // Compute gradients
            for (int j = 0; j < m; ++j) {
                double prediction = b0 + b1 * X[j];
                gradient_b0 += prediction - y[j];
                gradient_b1 += (prediction - y[j]) * X[j];
            }

            // Update parameters
            b0 -= learning_rate * gradient_b0 / m;
            b1 -= learning_rate * gradient_b1 / m;
        }

        this->b0 = b0;
        this->b1 = b1;
    }

    double predict(double x) {
        return b0 + b1 * x;
    }

private:
    double learning_rate;
    int n_iterations;
    double b0, b1;  // Coefficients
};

int main() {
    // Example data (X, y)
    std::vector<double> X = {1, 2, 4, 3, 5};
    std::vector<double> y = {1, 3, 3, 2, 5};

    // Create and train the model
    LinearRegression model(0.01, 1000);
    model.fit(X, y);

    // Make predictions
    std::cout << "Prediction for x=6: " << model.predict(6) << std::endl;

    return 0;
}
```

### How This Works:
- **Model Initialization**: The model is initialized with a learning rate and number of iterations.
- **Gradient Descent**: The `fit` function applies gradient descent to minimize the error between the predicted and actual values by updating the parameters.
- **Prediction**: The `predict` function makes predictions for new values.

### 5. **Optimizing ML Code in C++**
While C++ gives you great control, it also requires you to handle memory management and performance optimization manually. Some tips:
- **Use efficient data structures**.
- **Optimize matrix operations** with libraries like Eigen.
- **Parallelization**: Utilize multi-threading or GPU acceleration where possible.

### 6. **Machine Learning Workflows**
The typical workflow for ML in C++ follows these steps:
1. **Data Preprocessing**: Loading, normalizing, and splitting the data into training and test sets.
2. **Model Training**: Implementing or using existing algorithms to train the model on the dataset.
3. **Model Evaluation**: Evaluating the performance of the model using metrics like accuracy, precision, recall, etc.
4. **Optimization**: Fine-tuning hyperparameters and optimizing the code for performance.

### 7. **Using TensorFlow C++ API (Advanced)**
For more advanced models like deep learning, TensorFlow’s C++ API can be used to load pre-trained models or build custom models. However, this requires a more complex setup and understanding of TensorFlow’s architecture.


Certainly! I'll provide you with three examples of using C++ for machine learning problems. These examples will demonstrate how C++ can be used to implement basic machine learning algorithms and data preprocessing techniques.



```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <random>

// Example 1: Linear Regression
class LinearRegression {
private:
    double slope;
    double intercept;

public:
    void fit(const std::vector<double>& X, const std::vector<double>& y) {
        double sum_X = std::accumulate(X.begin(), X.end(), 0.0);
        double sum_Y = std::accumulate(y.begin(), y.end(), 0.0);
        double sum_XY = std::inner_product(X.begin(), X.end(), y.begin(), 0.0);
        double sum_XX = std::inner_product(X.begin(), X.end(), X.begin(), 0.0);
        int n = X.size();

        slope = (n * sum_XY - sum_X * sum_Y) / (n * sum_XX - sum_X * sum_X);
        intercept = (sum_Y - slope * sum_X) / n;
    }

    double predict(double x) const {
        return slope * x + intercept;
    }
};

// Example 2: K-Means Clustering
class KMeansClustering {
private:
    int k;
    std::vector<std::vector<double>> centroids;

public:
    KMeansClustering(int num_clusters) : k(num_clusters) {}

    void fit(std::vector<std::vector<double>>& data, int max_iterations = 100) {
        // Initialize centroids randomly
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, data.size() - 1);
        centroids.resize(k);
        for (int i = 0; i < k; ++i) {
            centroids[i] = data[dis(gen)];
        }

        for (int iteration = 0; iteration < max_iterations; ++iteration) {
            std::vector<std::vector<std::vector<double>>> clusters(k);
            
            // Assign points to nearest centroid
            for (const auto& point : data) {
                int nearest_centroid = 0;
                double min_distance = std::numeric_limits<double>::max();
                for (int i = 0; i < k; ++i) {
                    double distance = euclidean_distance(point, centroids[i]);
                    if (distance < min_distance) {
                        min_distance = distance;
                        nearest_centroid = i;
                    }
                }
                clusters[nearest_centroid].push_back(point);
            }

            // Update centroids
            for (int i = 0; i < k; ++i) {
                if (!clusters[i].empty()) {
                    centroids[i] = calculate_mean(clusters[i]);
                }
            }
        }
    }

    int predict(const std::vector<double>& point) const {
        int nearest_centroid = 0;
        double min_distance = std::numeric_limits<double>::max();
        for (int i = 0; i < k; ++i) {
            double distance = euclidean_distance(point, centroids[i]);
            if (distance < min_distance) {
                min_distance = distance;
                nearest_centroid = i;
            }
        }
        return nearest_centroid;
    }

private:
    double euclidean_distance(const std::vector<double>& a, const std::vector<double>& b) const {
        double sum = 0.0;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return std::sqrt(sum);
    }

    std::vector<double> calculate_mean(const std::vector<std::vector<double>>& points) const {
        std::vector<double> mean(points[0].size(), 0.0);
        for (const auto& point : points) {
            for (size_t i = 0; i < point.size(); ++i) {
                mean[i] += point[i];
            }
        }
        for (auto& m : mean) {
            m /= points.size();
        }
        return mean;
    }
};

// Example 3: Logistic Regression
class LogisticRegression {
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;

public:
    LogisticRegression(int features, double lr = 0.01) : learning_rate(lr) {
        weights.resize(features, 0.0);
        bias = 0.0;
    }

    void fit(const std::vector<std::vector<double>>& X, const std::vector<int>& y, int epochs = 100) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (size_t i = 0; i < X.size(); ++i) {
                double y_pred = predict_proba(X[i]);
                double error = y_pred - y[i];
                
                for (size_t j = 0; j < weights.size(); ++j) {
                    weights[j] -= learning_rate * error * X[i][j];
                }
                bias -= learning_rate * error;
            }
        }
    }

    bool predict(const std::vector<double>& x) const {
        return predict_proba(x) >= 0.5;
    }

private:
    double predict_proba(const std::vector<double>& x) const {
        double z = bias + std::inner_product(weights.begin(), weights.end(), x.begin(), 0.0);
        return 1.0 / (1.0 + std::exp(-z));
    }
};

int main() {
    // Example 1: Linear Regression
    std::vector<double> X = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};
    LinearRegression lr;
    lr.fit(X, y);
    std::cout << "Linear Regression prediction for x=6: " << lr.predict(6) << std::endl;

    // Example 2: K-Means Clustering
    std::vector<std::vector<double>> data = {{1, 2}, {1.5, 1.8}, {5, 8}, {8, 8}, {1, 0.6}, {9, 11}};
    KMeansClustering kmeans(2);
    kmeans.fit(data);
    std::cout << "K-Means Clustering prediction for point [2, 2]: " << kmeans.predict({2, 2}) << std::endl;

    // Example 3: Logistic Regression
    std::vector<std::vector<double>> X_log = {{1, 1}, {2, 2}, {2, 1}, {3, 4}};
    std::vector<int> y_log = {0, 0, 1, 1};
    LogisticRegression logreg(2);
    logreg.fit(X_log, y_log);
    std::cout << "Logistic Regression prediction for point [3, 3]: " << logreg.predict({3, 3}) << std::endl;

    return 0;
}

```

These examples demonstrate three basic machine learning algorithms implemented in C++:

1. **Linear Regression**: This example shows a simple implementation of linear regression. It fits a line to a set of data points and can make predictions based on the fitted line.

2. **K-Means Clustering**: This example implements the K-Means clustering algorithm. It groups a set of data points into K clusters based on their similarity.

3. **Logistic Regression**: This example demonstrates a basic implementation of logistic regression for binary classification. It learns to classify data points into one of two categories.

Key points about these implementations:

1. They are basic versions of these algorithms and don't include advanced features like regularization or optimization techniques.
2. They use standard C++ libraries and don't rely on external machine learning libraries.
3. These examples are meant for educational purposes and to demonstrate how machine learning concepts can be implemented in C++. For production use, it's generally recommended to use well-established libraries like TensorFlow, PyTorch, or scikit-learn, which offer more optimized and feature-rich implementations.

In practice, C++ is often used in machine learning for performance-critical parts of larger systems, often in conjunction with Python or other high-level languages for easier prototyping and experimentation.


### Conclusion
Machine Learning in C++ requires more setup and manual optimization compared to higher-level languages like Python. However, it’s incredibly powerful when performance matters. Libraries like MLPack, Dlib, and Eigen provide essential tools to make ML development easier in C++. For production environments, C++ often provides the speed and efficiency necessary for real-time applications and large-scale systems.

If you're starting with ML in C++, focus on understanding the core algorithms, using libraries for matrix operations, and gradually move towards more advanced topics like neural networks or integration with frameworks like TensorFlow.

### Problem Set
https://www.hackerrank.com/domains/ai
