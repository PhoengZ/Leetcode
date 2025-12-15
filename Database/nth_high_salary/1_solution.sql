CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (result_Salary INT) AS $$
BEGIN
  if n < 1 then return ;
  end if;
  RETURN QUERY (
    -- Write your PostgreSQL query statement below
	SELECT DISTINCT salary
    FROM employee
    ORDER BY salary DESC
    LIMIT 1 
    OFFSET N - 1  
  );
END;
$$ LANGUAGE plpgsql;