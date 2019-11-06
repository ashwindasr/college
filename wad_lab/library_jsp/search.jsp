<%-- 
    Document   : search
    Created on : 6 Nov, 2019, 11:35:37 PM
    Author     : ash
--%>

<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
        String isbn = request.getParameter("isbn");
        String id = null;
        
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
                id = rs.getString("isbn");
                if(id.equals(isbn))
                {
                    out.println("Book Name: "+rs.getString("name")+"<br />");
                    out.println("ISBN No: "+rs.getString("isbn")+"<br />");
                    out.println("Author: "+rs.getString("author")+"<br />");
                    out.println("<br />");
                }
                
            }
            conn.close();
       out.println("<br /><a href='index.jsp'>Go back to console</a>");
%>

