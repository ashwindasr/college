function unhide(value){
    var var1 = document.getElementById("div1");
    var var2 = document.getElementById("div2");
    var var3 = document.getElementById("div3");
    var var4 = document.getElementById("div4");
    var var5 = document.getElementById("div5");
    
    if(value == 1){
        var1.style.display = 'block';
        var2.style.display = 'none';
        var3.style.display = 'none';
        var4.style.display = 'none';
        var5.style.display = 'none';
    }
    else if(value == 2){
        var1.style.display = 'none';
        var2.style.display = 'block';
        var3.style.display = 'none';
        var4.style.display = 'none';
        var5.style.display = 'none';
    }
    else if(value == 3){
        var1.style.display = 'none';
        var2.style.display = 'none';
        var3.style.display = 'block';
        var4.style.display = 'none';
        var5.style.display = 'none';
    }
    else if(value == 4){
        var1.style.display = 'none';
        var2.style.display = 'none';
        var3.style.display = 'none';
        var4.style.display = 'block';
        var5.style.display = 'none';
    }
    else{
        var1.style.display = 'none';
        var2.style.display = 'none';
        var3.style.display = 'none';
        var4.style.display = 'none';
        var5.style.display = 'block';
    }
}