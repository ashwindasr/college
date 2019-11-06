<%-- 
    Document   : add
    Created on : 6 Nov, 2019, 11:09:57 PM
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
        
              Connection conn = DriverManager.getConnection(url,db_user,db_pass);
              Statement stmt = conn.createStatement();
              int i = stmt.executeUpdate("insert into library(name,isbn,author) values('"+name+"','"+isbn+"','"+author+"');");
              out.println("Successfully Registered");
              conn.close();
              out.println("<br /><br /><a href='index.jsp'>Go back to console</a>");
    
%>