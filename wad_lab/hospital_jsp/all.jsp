<%-- 
    Document   : all
    Created on : 31 Oct, 2019, 3:18:36 PM
    Author     : wad14
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
            Connection connection;
        String url = "jdbc:postgresql://localhost:5432/hospital";
        String db_user = "postgres";
        String db_pass = "root";
        String height = null;
        String name = null;
        String weight = null;
        String blood = null;
        String idno = null;
        try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                
                Boolean found = false;
                connection = DriverManager.getConnection(url, db_user, db_pass);
                Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select * from data;");
                while(rs.next())
                {
                        name = rs.getString("name");
                        height = rs.getString("height");
                        weight = rs.getString("weight");
                        blood = rs.getString("blood");
                        out.println("Name: "+name);
                        out.println("<br />");
                        out.println("Height: "+height);
                        out.println("<br />");
                        out.println("Weight: "+weight); 
                        out.println("<br />");
                        out.println("Blood group: "+blood); 
                        out.println("<br /><br />");
                }
                
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
%>
