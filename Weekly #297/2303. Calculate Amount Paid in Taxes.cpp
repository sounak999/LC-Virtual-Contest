class Solution {
    /*
    Steps:-
        1. We calculate taxable income amount which will be minimum b/w income and upper
        2. Now we calculate the amount of tax
        3. Now we calculate the remaining income for which next tax will be counted
        4. this will be done throughout the array
    */
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        // step 1 -> taxable income calculated
        int taxable = min(income, brackets[0][0]);
        // step 2 -> amount of tax
        double tax = taxable * brackets[0][1] / 100.00;
        // step 3 -> remaining income
        income -= taxable;
        
        int n = brackets.size();
        // step 4 -> rest of the array is processed
        for(int i=1; i<n && income > 0; i++)
        {
            int nextAmt = brackets[i][0] - brackets[i-1][0];
            taxable = min(nextAmt, income);
            tax += (taxable * brackets[i][1] / 100.00);
            income -= taxable;
        }
        
        return tax;
    }
};