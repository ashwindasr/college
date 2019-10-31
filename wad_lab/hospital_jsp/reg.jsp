<%-- 
    Document   : reg
    Created on : 31 Oct, 2019, 2:23:02 PM
    Author     : wad14
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
        String url = "jdbc:postgresql://localhost:5432/hospital";
        String db_user = "postgres";
        String db_pass = "root";
        
        String name = request.getParameter("name");
        String height = request.getParameter("height");
        String weight = request.getParameter("weight");
        String blood = request.getParameter("blood");
        
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
                int i = stmt.executeUpdate("INSERT INTO data(name,height,weight,blood) VALUES ('"+name+"','"+ height+"','"+ weight+"','"+blood+"');");
                out.println("Successfully registered !");
                out.println("<br /><a href='index.html'>Back to main page</a>");
                
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
%>