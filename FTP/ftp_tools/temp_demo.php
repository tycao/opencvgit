<?php

/*
$host = '192.168.183.128';
$port = '20';
$user = 'ftp';
$pwd = '1';
$con = ftp_connect("192.168.183.128", 21) or die("Shit, Failed Connection!");
var_dump($con);
$login = ftp_login($con,$user,$pwd);
echo ftp_put($con,'newname.txt','text.txt',FTP_ASCII);
ftp_close($con);
*/


// 连接FTP服务器  
$conn = ftp_connect("192.168.183.128");  

// 使用username和password登录  
ftp_login($conn, "ftp", "1");  


var_dump(ftp_pasv($conn, true));

$filelist = ftp_nlist($conn, "."); 
var_dump($filelist);

// 获取远端系统类型  
var_dump(ftp_systype($conn)); 

$here = ftp_pwd($conn); 
var_dump($here);
// 列示文件  
$filelist = ftp_nlist($conn, "."); 
// 下载文件  
ftp_get($conn, "demo.txt", "demo.txt", FTP_BINARY);  

//被动模式（PASV）的开关，打开或关闭PASV（1表示开）  
ftp_pasv($conn, 1);  

//建立或移动一个目录，这要使用ftp_mkdir()和ftp_rmdir()函数；注意：ftp_mkdir()建立成功的话，就会返回新建立的目录名。  
//ftp_mkdir($conn, "test"); 

//函数ftp_size()，它返回你所指定的文件的大小，使用BITES作为单位。要指出的是，如果它返回的是 "-1"的话，意味着这是一个目录  
$filelist = ftp_size($conn, "demo.txt");
var_dump($filelist);  

// 关闭联接  
ftp_quit($conn);  
?>