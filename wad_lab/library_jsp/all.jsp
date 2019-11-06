<%-- 
    Document   : all
    Created on : 6 Nov, 2019, 11:19:02 PM
    Author     : ash
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
        String name = null;
        String isbn = null;
        String author = null;
        
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
            ResultSet rs = stmt.executeQuery("select * from library");
            while(rs.next()){
                name = rs.getString("name");
                isbn = rs.getString("isbn");
                author = rs.getString("author");
                
                out.println("Book Name: "+name+"<br />");
                out.println("ISBN No: "+isbn+"<br />");
                out.println("Author: "+author+"<br />");
                out.println("<br />");
            }
            conn.close();
       out.println("<br /><a href='index.jsp'>Go back to console</a>");
%>
