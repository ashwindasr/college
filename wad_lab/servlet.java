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
 * @author ash
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
    protected void processRequestReg(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
         String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        
        String fname = request.getParameter("fname");
        String lname = request.getParameter("lname");
        String user = request.getParameter("user");
        String pass = request.getParameter("pass");
        
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
                int i = stmt.executeUpdate("INSERT INTO data(fname, lname, username, password) VALUES ('"+fname+"','"+ lname+"','"+ user+"','" + pass +"');");
                out.println("Successfully registered !");
                connection.close();
        } catch (SQLException ex) {
        out.println(ex.getMessage());        
        }
    }
    protected void processRequestLog(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection connection;
        String url = "jdbc:postgresql://localhost:5432/student";
        String db_user = "postgres";
        String db_pass = "root";
        String username = null;
        String password = null;
        PrintWriter out = response.getWriter();
        try {        
            Class.forName("org.postgresql.Driver");    
        } catch(ClassNotFoundException e ){
              //e.getMessage();
              out.println(e.getMessage());
        }    
        try {
                
                String user = request.getParameter("user");
                String pass = request.getParameter("pass");
                Boolean found = false;
                connection = DriverManager.getConnection(url, db_user, db_pass);
                out.println("Connected");
                Statement stmt = connection.createStatement();
                ResultSet rs = stmt.executeQuery("select * from data;");
                while(rs.next())
                {
                    username = rs.getString("username");
                    password = rs.getString("password");
                    if (username.equals(user)&&password.equals(pass))
                    {
                        found = true;
                        break;
                    }
                }
                if (true == found)
                {                    
                   out.println("Login success");                   
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
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
//    @Override
//    protected void doGet(HttpServletRequest request, HttpServletResponse response)
//            throws ServletException, IOException {
//        processRequest(request, response);
//    }

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
            out.println(reg_button);            
            if(reg_button.equals("Register"))
                processRequestReg(request, response);
            else
                processRequestLog(request, response);
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
