SELECT COUNT(*) FROM t_salary WHERE salary >= 2500
SELECT MIN(salary) FROM t_salary WHERE salary > 2500
SELECT MAX(salary) FROM t_salary WHERE salary < 2500
SELECT AVG(age) FROM t_salary WHERE gender = "Male"
SELECT SUM(salary) FROM t_salary WHERE gender = "Female"