<%-- 
    Document   : delete
    Created on : 6 Nov, 2019, 11:21:46 PM
    Author     : ash
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
        String isbn = request.getParameter("isbn");
        
        String url = "jdbc:postgresql://localhost:5432/postgres";
        String db_user = "postgres";
        String db_pass = "root";
        
        try{
            Class.forName("org.postgresql.Driver");
        }catch(ClassNotFoundException e){
            out.println(e.getMessage());
        }
        
              Connection conn = DriverManager.getConnection(url,db_user,db_pass);
              Statement stmt = conn.createStatement();
              int c=0;
              ResultSet rs = stmt.executeQuery("select * from library where isbn='"+isbn+"';");
            if(rs.next()){
                c = rs.getInt("copies");
                if(c>1)
                {
                    c -= 1;
                    int i = stmt.executeUpdate("update library set copies='"+c+"' where isbn='"+isbn+"';");
                    out.println("Updated successfully");
                    conn.close();
                    out.println("<br /><br /><a href='index.jsp'>Go back to console</a>");
                }
                else{
                    int i = stmt.executeUpdate("delete from library where isbn='"+isbn+"';");
              out.println("Successfully Deleted");
              conn.close();
              out.println("<br /><a href='index.jsp'>Go back to console</a>");
                }
                
            }
            
            
            
              
        
    
%>
