/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author wad14
 */
@WebServlet(urlPatterns = {"/servlet"})
public class servlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet servlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet servlet at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    protected void processRequestReg(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
         String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        
        String name = request.getParameter("name");
        String rollno = request.getParameter("rollno");
        String branch = request.getParameter("branch");
        
        Connection connection;
        PrintWriter out = response.getWriter();
                try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();                
                int i = stmt.executeUpdate("INSERT INTO data(name, rollno, department) VALUES ('"+name+"','"+ rollno+"','"+ branch+"');");
                out.println("Successfully registered !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
    }
protected void processRequestSearch(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection connection;
        String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        String roll = null;
        String name = null;
        String dept = null;
        PrintWriter out = response.getWriter();
        try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                
                String rollno = request.getParameter("rollno");
                Boolean found = false;
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select * from data;");
                while(rs.next())
                {
                    roll = rs.getString("rollno");
                    if (rollno.equals(roll))
                    {   
                        found = true;
                        break;
                    }
                }
                if (true == found)
                {                    
                        name = rs.getString("name");
                        dept = rs.getString("department");
                        out.println(name);
                        out.println(roll);
                        out.println(dept);                
                }
                else
                {
                    out.println("Login Failed");
                }
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        } 
    }

protected void processRequestDel(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
         String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        
        String rollno = request.getParameter("rollno");
        
        Connection connection;
        PrintWriter out = response.getWriter();
                try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();                
                int i = stmt.executeUpdate("delete from data where rollno='"+rollno+"';");
                out.println("Successfully Deleted !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
    }

protected void processRequestUp(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
         String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        
        String roll = request.getParameter("rollno");
        String name = request.getParameter("name");
        String dept = request.getParameter("branch");
        
        Connection connection;
        PrintWriter out = response.getWriter();
                try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();                
                int i = stmt.executeUpdate("update data set name='"+name+"', department='"+dept+"' where rollno='"+roll+"';");
                out.println("Successfully Updated !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
    }

protected void processRequestAll(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection connection;
        String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        String roll = null;
        String name = null;
        String dept = null;
        PrintWriter out = response.getWriter();
        try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                
                Boolean found = false;
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select * from data;");
                while(rs.next())
                {
                        roll = rs.getString("rollno");
                        name = rs.getString("name");
                        dept = rs.getString("department");
                        out.println(name);
                        out.println(roll);
                        out.println(dept);
                        out.println();
                }
                
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        } 
    }
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
             PrintWriter out = response.getWriter();
            String reg_button = request.getParameter("register");
                      
            if(reg_button.equals("Register"))
                processRequestReg(request, response); 
            else if(reg_button.equals("Search"))
                processRequestSearch(request, response);   
            else if(reg_button.equals("Delete"))
                processRequestDel(request, response); 
            else if(reg_button.equals("Update"))
                processRequestUp(request, response); 
            else
                  processRequestAll(request, response);  
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
