<%-- 
    Document   : search
    Created on : 31 Oct, 2019, 2:36:43 PM
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
                
                String id = request.getParameter("id");
                Boolean found = false;
                connection = DriverManager.getConnection(url, db_user, db_pass);
                Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select * from data;");
                while(rs.next())
                {
                    idno = rs.getString("id");
                    if (idno.equals(id))
                    {   
                        found = true;
                        break;
                    }
                }
                if (true == found)
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
                }
                else
                {
                    out.println("Login Failed");
                }
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
%>