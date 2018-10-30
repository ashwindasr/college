int incr(int n){
  return n+1;
}

CREATE OR REPLACE FUNCTION inc(n INT)
RETURNS INT AS 
$BODY$
BEGIN
  RETURN n+1;
END;
$BODY$
LANGUAGE plpgsql;
