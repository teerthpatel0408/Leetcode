SELECT 'Low Salary' AS category, SUM(IF(income < 20000,1,0)) AS accounts_count 
FROM accounts
UNION
SELECT 'High Salary' AS category, SUM(IF(income > 50000,1,0)) AS accounts_count 
FROM accounts
UNION
SELECT 'Average Salary' AS category, SUM(IF(income >= 20000 and income <= 50000,1,0)) AS accounts_count 
FROM accounts