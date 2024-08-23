class Solution {
private:
    int GCD(int a,int b){
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int LCM(int a, int b) {
        return (a * b) / GCD(a, b);
    }
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++;

            int denom = 0;
            while (i < n && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }

            int lcm = LCM(denominator, denom);

            numerator = numerator * (lcm / denominator) + num * (lcm / denom);
            denominator = lcm;

            int gcd = GCD(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};