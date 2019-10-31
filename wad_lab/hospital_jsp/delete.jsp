<%-- 
    Document   : delete
    Created on : 31 Oct, 2019, 3:07:22 PM
    Author     : wad14
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
        String url = "jdbc:postgresql://localhost:5432/hospital";
        String db_user = "postgres";
        String db_pass = "root";
        
        String id = request.getParameter("id");
        
        Connection connection;
                try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                connection = DriverManager.getConnection(url, db_user, db_pass);
                Statement stmt = connection.createStatement();                
                int i = stmt.executeUpdate("delete from data where id='"+id+"';");
                out.println("Successfully Deleted !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
%>