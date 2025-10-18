#include <UnitTest++/UnitTest++.h>
#include "Polynomial.h"

TEST(DefaultConstructor) {
    Polynomial p;
    CHECK_EQUAL(0, p[0]);
}

TEST(DegreeConstructor) {
    Polynomial p(2);
    CHECK_EQUAL(0, p[0]);
    CHECK_EQUAL(0, p[1]);
    CHECK_EQUAL(0, p[2]);
}
TEST(InputStream) {
    Polynomial p(2);
    std::istringstream iss("1 2 3");

    iss >> p;

    CHECK_EQUAL(p[0], 1);
    CHECK_EQUAL(p[1], 2);
    CHECK_EQUAL(p[2], 3);
}
TEST(CopyConstructor) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(p1);
    CHECK_EQUAL(p1[0], p2[0]);
    CHECK_EQUAL(p1[1], p2[1]);
    CHECK_EQUAL(p1[2], p2[2]);
}
TEST(AssignmentOperator) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2;
    p2 = p1;

    CHECK_EQUAL(p1[0], p2[0]);
    CHECK_EQUAL(p1[1], p2[1]);
    CHECK_EQUAL(p1[2], p2[2]);
}

TEST(EqualityOperator) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(2);
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 3;

    CHECK(p1 == p2);
}

TEST(InequalityOperator) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(2);
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 4;

    CHECK(p1 != p2);
}
TEST(AdditionWithZeroCoefficients) {
    Polynomial p1(2);
    Polynomial p2(2);

    p1[0] = 0;
    p1[1] = 0;
    p1[2] = 2; 

    p2[0] = 1; 

    Polynomial result = p1 + p2; 

    CHECK_EQUAL(result[0], 1);
    CHECK_EQUAL(result[1], 0);
    CHECK_EQUAL(result[2], 2);
}
TEST(SubtractionWithZeroCoefficients) {
    Polynomial p1(2);
    Polynomial p2(2);

    p1[0] = 3; 
    p1[1] = 0;
    p1[2] = 2; 

    p2[0] = 1; 
    p2[1] = 2; 

    Polynomial result = p1 - p2; 

    CHECK_EQUAL(result[0], 2);
    CHECK_EQUAL(result[1], -2);
    CHECK_EQUAL(result[2], 2);
}
TEST(Addition) {
    Polynomial p1(2);
    p1[0] = 1; 
    p1[1] = 2; 
    p1[2] = 3; 

    Polynomial p2(2);
    p2[0] = 2; 
    p2[1] = 3; 
    p2[2] = 1; 

    Polynomial result = p1 + p2;

    CHECK_EQUAL(3, result[0]); 
    CHECK_EQUAL(5, result[1]); 
    CHECK_EQUAL(4, result[2]); 
}

TEST(Subtraction) {
    Polynomial p1(2);
    p1[0] = 5; 
    p1[1] = 6;
    p1[2] = 7;

    Polynomial p2(2);
    p2[0] = 2;
    p2[1] = 3;
    p2[2] = 1;

    Polynomial result = p1 - p2;

    CHECK_EQUAL(3, result[0]); 
    CHECK_EQUAL(3, result[1]); 
    CHECK_EQUAL(6, result[2]); 
}

TEST(Multiplication) {
    Polynomial p1(1);
    p1[0] = 2; 
    p1[1] = 3; 

    Polynomial p2(1);
    p2[0] = 1; 
    p2[1] = 4; 

    Polynomial result = p1 * p2;

    CHECK_EQUAL(2, result[0]);
    CHECK_EQUAL(11, result[1]);
    CHECK_EQUAL(12, result[2]);
}

TEST(Division) {
    Polynomial p1(2);
    p1[0] = 6; 
    p1[1] = 5; 
    p1[2] = 1; 

    Polynomial p2(1);
    p2[0] = 2; 
    p2[1] = 1; 

    Polynomial result = p1 / p2;

    CHECK_EQUAL(3, result[0]); 
    CHECK_EQUAL(1, result[1]); 
}

TEST(ValueCalculation) {
    Polynomial p(2);
    p[0] = 1; 
    p[1] = -2;
    p[2] = 3; 

    double value = p(2); 
    CHECK_EQUAL(9, value);
}

TEST(ZeroPolynomial) {
    Polynomial p(0);
    CHECK_EQUAL(0, p(1));
}

TEST(PolynomialWithNegativeCoefficients) {
    Polynomial p(2);
    p[0] = -1;
    p[1] = -2;
    p[2] = -3;

    CHECK_EQUAL(-1, p(0));
    CHECK_EQUAL(-6, p(1));
    CHECK_EQUAL(-17, p(2));
}

TEST(AdditionWithZero) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(0); 

    Polynomial result = p1 + p2;
    CHECK_EQUAL(p1[0], result[0]);
    CHECK_EQUAL(p1[1], result[1]);
    CHECK_EQUAL(p1[2], result[2]);
}

TEST(MultiplicationWithZero) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(0); 

    Polynomial result = p1 * p2;
    CHECK_EQUAL(0, result[0]);
}
TEST(DegreeIncreasedAfterMultiplication) {
    Polynomial p1(1);
    p1[0] = 1; 
    p1[1] = 1; 

    Polynomial p2(1);
    p2[0] = 1; 
    p2[1] = 1; 

    Polynomial result = p1 * p2;
    CHECK_EQUAL(1, result[0]);
    CHECK_EQUAL(2, result[1]); 
    CHECK_EQUAL(1, result[2]); 
}

TEST(PolynomialWithHigherDegree) {
    Polynomial p(4); 
    p[0] = 1;
    p[1] = 0;
    p[2] = -1;
    p[3] = 2;
    p[4] = 3;

    CHECK_EQUAL(1, p[0]);
    CHECK_EQUAL(0, p[1]);
    CHECK_EQUAL(-1, p[2]);
    CHECK_EQUAL(2, p[3]);
    CHECK_EQUAL(3, p[4]);
}

TEST(CalculateValueAtNegativeX) {
    Polynomial p(2);
    p[0] = 1; 
    p[1] = -2;
    p[2] = 3; 

    double value = p(-2); 
    CHECK_EQUAL(17, value);
}

TEST(AdditionOfPolynomialsWithDifferentDegrees) {
    Polynomial p1(2); 
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;

    Polynomial p2(1); 
    p2[0] = 2;
    p2[1] = 3;

    Polynomial result = p1 + p2;

    CHECK_EQUAL(3, result[0]);
    CHECK_EQUAL(5, result[1]);
    CHECK_EQUAL(3, result[2]);
}

TEST(SubtractionOfPolynomialsWithDifferentDegrees) {
    Polynomial p1(2); 
    p1[0] = 5;
    p1[1] = 6;
    p1[2] = 7;

    Polynomial p2(1); 
    p2[0] = 2;
    p2[1] = 3;

    Polynomial result = p1 - p2;

    CHECK_EQUAL(3, result[0]); 
    CHECK_EQUAL(3, result[1]); 
    CHECK_EQUAL(7, result[2]); 
}

TEST(MultiplicationWithNegativeCoefficient) {
    Polynomial p1(1);
    p1[0] = -1;
    p1[1] = 2; 

    Polynomial p2(1);
    p2[0] = 3; 
    p2[1] = -4;

    Polynomial result = p1 * p2;

    CHECK_EQUAL(-3, result[0]); 
    CHECK_EQUAL(10, result[1]); 
    CHECK_EQUAL(-8, result[2]); 
}

TEST(EmptyPolynomialOperations) {
    Polynomial p1(0);
    Polynomial p2(0);
    
    Polynomial sum = p1 + p2;
    CHECK_EQUAL(0, sum[0]);
    
    Polynomial diff = p1 - p2;
    CHECK_EQUAL(0, diff[0]);
    
    Polynomial prod = p1 * p2;
    CHECK_EQUAL(0, prod[0]);
}

TEST(SingleCoefficientPolynomial) {
    Polynomial p(0);
    p[0] = 5;
    
    CHECK_EQUAL(5, p(0));
    CHECK_EQUAL(5, p(1));
    CHECK_EQUAL(5, p(10));
}

TEST(StreamOutputTest) {
    Polynomial p(2);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    
    std::ostringstream oss;
    oss << p;
    CHECK(oss.str().find("3x^2") != std::string::npos);
    CHECK(oss.str().find("2x^1") != std::string::npos);
    CHECK(oss.str().find("1x^0") != std::string::npos);
}

TEST(StreamInputTest) {
    Polynomial p(2);
    std::istringstream iss("1.0 2.0 3.0");
    iss >> p;
    
    CHECK_EQUAL(1.0, p[0]);
    CHECK_EQUAL(2.0, p[1]);
    CHECK_EQUAL(3.0, p[2]);
}

TEST(SelfAssignmentTest) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    
    Polynomial& p2 = p1;
    p1 = p2;
    CHECK_EQUAL(1, p1[0]);
    CHECK_EQUAL(2, p1[1]);
    CHECK_EQUAL(3, p1[2]);
}

TEST(EdgeCaseDivision) {
    Polynomial p1(0);
    p1[0] = 5;
    
    Polynomial p2(0);
    p2[0] = 1;
    
    Polynomial result = p1 / p2;
    CHECK_EQUAL(5, result[0]);
}

TEST(HighDegreePolynomial) {
    Polynomial p(10);
    for (int i = 0; i <= 10; ++i) {
        p[i] = i + 1;
    }
    double value = p(1.0);
    CHECK_CLOSE(66.0, value, 1e-10);
}

TEST(PolynomialWithZeroLeadingCoefficient) {
    Polynomial p(3);
    p[0] = 1;
    p[1] = 2;
    p[2] = 0; 
    p[3] = 4;
    CHECK_EQUAL(1, p[0]);
    CHECK_EQUAL(2, p[1]);
    CHECK_EQUAL(0, p[2]);
    CHECK_EQUAL(4, p[3]);
}
TEST(DivisionByZeroPolynomial) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 1;
    
    Polynomial p2(0); 
    CHECK_THROW(p1 / p2, std::invalid_argument);
}

TEST(DivisionByAllZeroPolynomial) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 1;
    
    Polynomial p2(2); 
    p2[0] = 0;
    p2[1] = 0;
    p2[2] = 0;
    
    CHECK_THROW(p1 / p2, std::invalid_argument);
}

TEST(SimpleDivision) {
    Polynomial p1(1);
    p1[0] = 6;
    p1[1] = 3; 
    
    Polynomial p2(0);
    p2[0] = 3; 
    
    Polynomial result = p1 / p2; 
    CHECK_EQUAL(2, result[0]);
    CHECK_EQUAL(1, result[1]);
}


TEST(CompoundAssignmentOperators) {
    Polynomial p1(2);
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3; 
    
    Polynomial p2(1);
    p2[0] = 1;
    p2[1] = 1;    
    p1 += p2;
    CHECK_EQUAL(2, p1[0]); 
    CHECK_EQUAL(3, p1[1]); 
    CHECK_EQUAL(3, p1[2]); 
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    
    p1 -= p2;
    CHECK_EQUAL(0, p1[0]); 
    CHECK_EQUAL(1, p1[1]); 
    CHECK_EQUAL(3, p1[2]); 
    
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    
    p1 *= p2;
    CHECK_EQUAL(1, p1[0]); 
    CHECK_EQUAL(3, p1[1]); 
    CHECK_EQUAL(5, p1[2]); 
    CHECK_EQUAL(3, p1[3]); 
}
int main() {
    return UnitTest::RunAllTests();
}
