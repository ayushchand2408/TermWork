INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2001, 'Aarav Sharma', 'HR', 28, 60000, 'Delhi');
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2002, 'Priya Singh', 'IT', 32, 75000, 'Pune');
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2003, 'Rahul Verma', 'Finance', 25, 55000, 'Mumbai');
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2004, 'Anjali Gupta', 'HR', 35, 80000, 'Delhi');
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2005, 'Vikram Khan', 'IT', 40, 90000, 'Pune');
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY) VALUES (2006, 'Sneha Joshi', 'Finance', 29, 65000, 'Mumbai');

select
case
when e1.city= any(select e2.city from employee e2)
then 'same city'
else 'not same city'
end
as result
from employee e1
where rownum;

select
case
when e1.city= all(select e2.city from employee e2)
then 'same city'
else 'not same city'
end
as result
from employee e1
where rownum;

select
case
when exists(select e2.city from employee e2 where e1.city <> e2.city)
then 'not same city'
else 'same city'
end
as result
from employee e1
where rownum;

INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY)
VALUES (101, 'John Doe', 'Sales', 35, 60000, 'New York');

INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY)
VALUES (102, 'Jane Smith', 'Marketing', 28, 55000, 'Los Angeles');

-- Insert the third record
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY)
VALUES (103, 'Peter Jones', 'IT', 42, 85000, 'Chicago');

-- Insert the fourth record
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY)
VALUES (104, 'Emily White', 'HR', 25, 45000, 'Houston');

-- Insert the fifth record
INSERT INTO employee (EMPLOYEE_ID, NAME, DEPARTMENT, AGE, SALARY, CITY)
VALUES (105, 'Michael Brown', 'Finance', 50, 95000, 'New York');

CREATE TABLE employee (
    Emp_ID NUMBER PRIMARY KEY,
    Dep_ID NUMBER,
    Name VARCHAR(20) NOT NULL,
    Age NUMBER CHECK(Age > 18),
    Salary NUMBER,
    City VARCHAR(20),
    CONSTRAINT fk_employee_department
        FOREIGN KEY (Dep_ID)
        REFERENCES department(Dep_ID)
);

alter table employee and constraint fkey foreign key(Dept_ID) refrences department(Dept_ID);

select name ,dname from employee inner join department on 
employee.Dept_ID = department.Dept_ID ; 