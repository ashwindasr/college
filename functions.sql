int incr(int n){
  return n+1;
}
/* Function to increment a number */
CREATE OR REPLACE FUNCTION inc(n INT)
RETURNS INT AS 
$BODY$
BEGIN
  RETURN n+1;
END;
$BODY$
LANGUAGE plpgsql;

/* Function to calculate sum of two numbers */
CREATE OR REPLACE FUNCTION sum_of_two(a INT,b INT)
RETURNS INT AS
$BODY$
BEGIN
  RETURN a+b;
END;
$BODY$
LANGUAGE plpgsql;

/* Dont forget ; at the end of RETURN */

/* Function to calculate nth fibanocci series */
CREATE OR REPLACE FUNCTION fib(n INT)
RETURNS INT AS
$BODY$
DECLARE
  a INT = 0;
  b INT = 1;
  c INT = 0;
BEGIN
  IF n=1 THEN
    RETURN 0;
  ELSIF n=2 THEN
    RETURN 1;
  ELSE
    LOOP 
    EXIT WHEN n=2; 
     c=a+b;
     a=b;
     b=c;
     n=n-1;
    END LOOP;
    RETURN c;
  END IF;
END;
$BODY$
LANGUAGE plpgsql;
