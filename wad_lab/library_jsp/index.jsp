<%-- 
    Document   : index
    Created on : 6 Nov, 2019, 11:08:55 PM
    Author     : ash
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Library</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script type="text/javascript" src="hide.js"></script>
    </head>
    <body>
        <h1 align="center">Library Management System</h1>
        <div align="center">
            <button onclick="unhide(1)">Add</button>
            <button onclick="unhide(2)">Update</button>
            <button onclick="unhide(4)">Search</button>
            <button onclick="unhide(3)">Delete</button>
            <button onclick="unhide(5)">All</button>
        </div>
        <div>
            <div id="div1" align="center">
                <fieldset style="width:200px">
                    <legend>Add a book</legend>
                    <form method="post" action="add.jsp">
                        Book name: <input type="text" name="name" required autofocus/><br /><br />
                        ISBN No: <input type="text" name="isbn" required /><br /><br />
                        Author: <input type="text" name="author" required /><br /><br />
                        <input type="submit" value="Add" />
                    </form>
                </fieldset>
            </div>
            
            <div id="div2" align="center" hidden>
                <fieldset style="width:200px">
                    <legend>Update a book</legend>
                    <form method="post" action="update.jsp">
                        Book name: <input type="text" name="name" required autofocus/><br /><br />
                        ISBN No: <input type="text" name="isbn" required /><br /><br />
                        Author: <input type="text" name="author" required /><br /><br />
                        <input type="submit" value="Update" />
                    </form>
                </fieldset>
            </div>
            <div id="div3" align="center" hidden>
                <fieldset style="width:200px">
                    <legend>Delete a book</legend>
                    <form method="post" action="delete.jsp">
                        ISBN No: <input type="text" name="isbn" required /><br /><br />
                        <input type="submit" value="Delete" />
                    </form
                </fieldset>
            </div>
            <div id="div4" align="center" hidden>
                <fieldset style="width:200px">
                    <legend>Search for a book</legend>
                    <form method="post" action="search.jsp">
                        ISBN No: <input type="text" name="isbn" required /><br /><br />
                        <input type="submit" value="Search" />
                    </form>
                </fieldset>
            </div>
            <div id="div5" align="center" hidden>
                <fieldset style="width:200px">
                    <legend>Display all books</legend>
                    <form method="post" action="all.jsp">
                        <input type="submit" value="Click here" />
                    </form>
                </fieldset>
            </div>
        </div>
    </body>
</html>

