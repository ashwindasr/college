<%-- 
    Document   : update
    Created on : 31 Oct, 2019, 3:12:39 PM
    Author     : wad14
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
            String url = "jdbc:postgresql://localhost:5432/hospital";
        String db_user = "postgres";
        String db_pass = "root";
        
        String id = request.getParameter("id");
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
                int i = stmt.executeUpdate("update data set name='"+name+"', height='"+height+"', weight='"+weight+"', blood='"+blood+"' where id='"+id+"';");
                out.println("Successfully Updated !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
%>