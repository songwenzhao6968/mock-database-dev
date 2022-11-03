USE SECURE
SELECT AVG(salary) FROM t_salary WHERE age = 32
SELECT SUM(*) FROM t_salary WHERE age = 25
SELECT COUNT(*) FROM t_salary WHERE age = 30
SELECT SUM(age) FROM t_salary WHERE name = "Cinder"
SELECT AVG(age) FROM t_salary WHERE gender = "Male"
