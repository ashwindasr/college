<%-- 
    Document   : update
    Created on : 6 Nov, 2019, 11:17:15 PM
    Author     : ash
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<% 
        String name = request.getParameter("name");
        String isbn = request.getParameter("isbn");
        String author = request.getParameter("author");
        
        String url = "jdbc:postgresql://localhost:5432/postgres";
        String db_user = "postgres";
        String db_pass = "root";
        
        try{
            Class.forName("org.postgresql.Driver");
        }catch(ClassNotFoundException e){
            out.println(e.getMessage());
        }
        
        Connection conn = DriverManager.getConnection(url, db_user, db_pass);
        Statement stmt = conn.createStatement();
        int i = stmt.executeUpdate("update library set name='"+name+"', author='"+author+"' where isbn='"+isbn+"';");
        out.println("Updated successfully");
        conn.close();
        out.println("<br /><br /><a href='index.jsp'>Go back to console</a>");
   
%>
