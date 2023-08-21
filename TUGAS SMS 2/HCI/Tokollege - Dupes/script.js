function setTokoStatus(status)
{
    localStorage.setItem('tokoStatus', status);
}

function getTokoStatus()
{
    return localStorage.getItem('tokoStatus');
}

function validateUsername(username) {
    var usernameRegex = /^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]+$/;
    return usernameRegex.test(username);
}

function validateEmail(email) {
    var emailRegex = /^[^\s@]+@gmail\.com$/;
    return emailRegex.test(email);
}

function validatePassword(password) {
    var passwordRegex = /^(?=.*[a-zA-Z])(?=.*[0-9])(?=.*[^a-zA-Z0-9])[\S]{8,}$/;
    return passwordRegex.test(password);
}

function validateNohp(nohp){
    var validasiAngka = /^[0-9]+$/;
    return validasiAngka.test(nohp);
}

function checkInputToko(){
    var nohp=document.getElementById("NoHP").value;
    var namatoko=document.getElementById("namatoko").value;
    var namadomain=document.getElementById("domain").value;
    var deskripsitoko=document.getElementById("deskripsitoko").value;
    
    if(nohp === null || nohp===""){
        alert("Nomor Handphone tidak boleh kosong, masukkan No HP!");
        return;
    }
    if(!validateNohp(nohp)){
        alert('Nomor Handphone harus angka, tidak boleh karakter lain!');
        return;
    }
    if(namatoko === null || namatoko===""){
        alert("Nama Toko tidak boleh kosong, mmasukkan nama toko!");
        return;
    }
    if(namadomain === null || namadomain===""){
        alert("Nomor Domain tidak boleh kosong, masukkan nama domain!");
        return;
    }
    if(deskripsitoko === null || deskripsitoko===""){
        alert("Deskripsi Toko tidak boleh kosong, mmasukkan deskripsi toko!");
        return;
    }

    var penjualData = {
        nohp: nohp,
        namatoko: namatoko,
        namadomain:namadomain,
        deskripsitoko:deskripsitoko,
      };
      localStorage.setItem(nohp, JSON.stringify(penjualData));

      window.location.href = "berandatoko.html";

}

function saveCredentials() //Register
{
    var username=document.getElementById("username").value;
    var email = document.getElementById('email').value;
    var password = document.getElementById('password').value;
    var confirmPassword = document.getElementById('confirmPassword').value;
    var tokoStatus = getTokoStatus();

    if(username === null || username === ""){
        alert('Username tidak boleh kosong, masukkan username!');
        return;
    }

    if(!validateUsername(username)){
        alert('Username harus memiliki kombinasi huruf dan angka!');
        return;
    }

    if(email === null || email === ""){
        alert('Email tidak boleh kosong, masukkan email!');
        return;
    }
    
    if (!validateEmail(email)) {
        alert('Email harus memiliki format yang valid! contoh: example@gmail.com');
        return;
    }        
    

    if(password === null || password === ""){
        alert('Password tidak boleh kosong, masukkan password!');
        return;
    }
    
    if (!validatePassword(password)) {
        alert('Password harus terdiri dari setidaknya 8 karakter dan memiliki kombinasi huruf, angka, dan simbol!');
        return;
    }

    if (password !== confirmPassword)
    {
        alert('Password dan Confirm Password tidak cocok!');
        return;
    }
  

    var userData = {
        username: username,
        password: password,
      };
    
    localStorage.setItem(email, JSON.stringify(userData));

    // localStorage.setItem('email', email);
    // localStorage.setItem(email, JSON.stringify({ username: username, password: password }));

    // localStorage.setItem('email', email);
    // localStorage.setItem(email, password);
    // localStorage.setItem(email,username);
  
    if (tokoStatus === 'penjualSudahPunya')
    {
        window.location.href = "berandatoko.html";
    }
    
    else if (tokoStatus === 'penjualBelumPunya')
    {
        window.location.href = "buattoko.html";
    }
    
    else if (tokoStatus === 'pembeli')
    {
        window.location.href = "beranda.html";
    }
}

function checkCredentials() { //Login
    var email = document.getElementById('email').value;
    var password = document.getElementById('password').value;
    var tokoStatus = getTokoStatus();
    var matchFound = false;
    var emailExists = false;

    if (email === null || email === "") {
        alert('Email tidak boleh kosong, masukkan email!');
        return;
    }
    
    if (!validateEmail(email)) {
        alert('Email harus memiliki format yang valid! contoh: example@gmail.com');
        return;
    }        

    if (password === null || password === "") {
        alert('Password tidak boleh kosong, masukkan password!');
        return;
    }
    
    if (!validatePassword(password)) {
        alert('Password harus terdiri dari setidaknya 8 karakter dan memiliki kombinasi huruf, angka, dan simbol!');
        return;
    }

    for (var i = 0; i < localStorage.length; i++) {
        var key = localStorage.key(i);
        if (key === email) {
            emailExists = true;
            var storedData = JSON.parse(localStorage.getItem(key));
            if (storedData.password === password) {
                matchFound = true;
                break;
            }
        }
    }

    if (!emailExists) {
        alert('Email tidak terdaftar!');
        return;
    }

    if (matchFound) {
        if (tokoStatus === 'penjualSudahPunya') {
            window.location.href = "berandatoko.html";
        } else if (tokoStatus === 'penjualBelumPunya') {
            window.location.href = "buattoko.html";
        } else if (tokoStatus === 'pembeli') {
            window.location.href = "beranda.html";
        }
    } else {
        alert('Email atau password tidak cocok!');
        return;
    }
}