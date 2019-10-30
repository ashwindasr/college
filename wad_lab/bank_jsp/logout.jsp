<%-- 
    Document   : logout
    Created on : 30 Oct, 2019, 8:15:53 PM
    Author     : ash
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    session.invalidate();
    response.sendRedirect("login.html");
%>