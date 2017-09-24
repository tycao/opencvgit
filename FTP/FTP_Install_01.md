UBuntu16.10下安装ftp服务
------------------------
### 首先更新软件源，保证源是最新的，这样有利于保证在线通过apt-get install命令安装ftp。
	sudo apt-get update
### 安装vsftp : 使用sudo apt-get install vsftp命令安装vsftp，安装软件需要root权限，我们使用sudo来暂时获取。
	sudo apt-get install vsftpd
### 安装好ftp后默认是会自动创建ftp用户的，然后我们设置ftp用户的密码，输入 sudo passwd ftp，然后输入密码，再确认密码。
	sudo passwd ftp
### 创建ftp用户的家目录，使用sudo mkdir /home/ftp命令
	sudo mkdir /home/ftp
### 设置ftp家目录的权限，我这里为方便直接使用 sudo chmod 777 /home/ftp 命令将权限设置为777，当然你可以根据自己需求进行设置。
	sudo chmod 777 /home/ftp
### 对/etc/vsftpd.conf配置文件进行一定的修改。使用 sudo vi /etc/vsftpd.conf打开配置文件，如果你喜欢vim编辑器也可以使用它打开。
	sudo vi /etc/vsftpd.conf
* 打开/etc/vsftpd.conf配置文件后，对配置文件的内容进行一系列必要的修改：
	* 将配置文件中”anonymous_enable=YES “改为 “anonymous_enable=NO”（是否允许匿名ftp，若不允许选NO）
	* 取消如下配置前的注释符号：
		* local_enable=YES（是否允许本地用户登录）
		* write_enable=YES（是否允许本地用户写的权限）
		* chroot_local_user=YES（是否将所有用户限制在主目录）
		* chroot_list_enable=YES（是否启动限制用户的名单）
		* chroot_list_file=/etc/vsftpd.chroot_list（可在文件中设置多个账号）
![ftp_02](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
![ftp_01](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_01.png "ftp_01")
### 然后创建上述chroot_list_file文件的路径 ： /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
然后在/etc/vsftpd.chroot_list文件里，添加ftp用户：ftp
![ftp_03](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_03.png "ftp_03")

### 测试ftp，复制一些文件到/home/ftp目录下
* 方法一：在浏览器中输入ftp://localhost，网页登录。
![ftp_05](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_05.png "ftp_05")
![ftp_06](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_06.png "ftp_06")
* 方法二：在终端中输入ftp localhost，然后输入用户名与密码实现登录。
![ftp_04](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_04.png "ftp_04")
* 方法三：在Windows下，使用 "ftp:ip_address" (ip_address代表UBuntu的内网ip地址)来登陆链接UBuntu的ftp服务
![ftp_11](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_11.png "ftp_11")

### 如果登录ftp总是出现密码错误，可以将/etc/vsftpd.conf配置文件的pam_service_name=vsftpd改为pam_service_name=ftp，即可解决。
![ftp_07](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_07.png "ftp_07")
### 链接
[具体可以参考百度经验，还是蛮有用的](https://jingyan.baidu.com/article/7908e85c988b23af481ad2ae.html)



	
	
ubuntu下安装vftp 安装vsftpd后，登录ftp服务器时，会提示错误： 530 Login incorrect
==================================================
* 更换国内源；

* 刷新源：sudo apt-get update

* sudo apt-get install vsftpd

* 新建"/home/uftp"目录作为用户主目录打开"终端窗口"，输入"sudo mkdir /home/uftp"-->回车-->输入"sudo ls /home"-->回车-->有一个uftp目录，目录新建成功。

* 新建用户uftp并设置密码打开"终端窗口"，输入"sudo useradd -d /home/uftp -s /bin/bash uftp"-->回车-->用户新建成功-->输入"sudo passwd uftp"设置uftp用户的密码-->回车-->输入两次密码-->回车-->密码设置成功。

* 使用gedit修改配置文件/etc/vsftpd.conf打开"终端窗口"，输入"sudo gedit /etc/vsftpd.conf"-->回车-->打开了vsftpd.conf文件，向文件中添加:
	* userlist_deny=NO 
	* userlist_enable=YES 
	* userlist_file=/etc/allowed_users
	* seccomp_sandbox=NO -->使文件中的"local_enable=YES"-->保存。
![ftp_08](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_08.png "ftp_08")
!["ftp_02"](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
### 然后在上述 userlist_file=/etc/allowed_users 下创建 /etc/allowed_users
	touch /etc/allowed_users
	sudo chmod 777 /etc/allowed_users
	在/etc/allowed_users里添加ftp用户：ftp

![ftp_09](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_09.png "ftp_09")

* 使用gedit查看/etc/ftpusers文件中的内容打开"终端窗口"，输入"sudo gedit /etc/ftpusers"-->回车-->打开这个文件后，看一看有没有uftp这个用户名，如果没有，就直接退出。如果有就删除uftp,
因为这个文件中记录的是不能访问FTP服务器的用户清单。（去掉root）


### 链接
[具体如何解决 "530 Login incorrect" 的ftp登录问题，可以参考此链接](http://www.cnblogs.com/bqx619/p/5021458.html)




接下来，才算是进入了主题 O(∩_∩)O没错，以上都是环境的搭建。到这里才是所讲的主题：使用PHP的API登录FTP服务器。对文件进行操作：
-----------------------------
### 先上图：
在我的UBuntu上的内网ip地址如下所示：
![ftp_10](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_10.png "ftp_10")
使用PHP的登录界面如下所示：
![ftp_12](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_12.png "ftp_12")
![ftp_13](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_13.png "ftp_13")
![ftp_14](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_14.png "ftp_14")
![ftp_15](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_15.png "ftp_15")

### PHP程序的整个目录树应该时这个样子的：
![ftp_16](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_16.png "ftp_16")
### 首先，我们进入的首页面是index.php页面：
#### index.php
```php
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>FTP Tools Login</title>
	<link rel="stylesheet" type="text/css" href="css/login-style.css">
	<script type="text/javascript" src="js/jquery-2.2.1.min.js"></script>
	<script type="text/javascript" src="js/jquery.cookie.js"></script>
	<script type="text/javascript" src="js/login.js"></script>
</head>
<body>
	<div id="logo">
		<img src="images/mega.png" width="160px" height="160px">
	</div>
	<div id="ftp_section">
		<form action="web_login.php" id="ftp_info" method="POST">
			<p id="hintText" class="hintOk">登陆FTP服务器</p>
			<p><input type="text" id="ftp_host" name="ftp_host" placeholder="域名/IP地址"></input></p>
			<p><input type="text" id="ftp_port" name="ftp_port" placeholder="端口"></input></p>
			<p><input type="text" id="ftp_user" name="ftp_user" placeholder="用户名"></input></p>
			<p><input type="password" id="ftp_pwd" name="ftp_pwd" placeholder="密码"></input></p>
			<p><input type="submit" id="submit_button" class="submit_buttonOk" value="立即登陆"></input></p>
		</form>
	</div>
</body>
</html>
```

### 当我们输入完成信息，且成功登录UBuntu上的FTP server后，我们进入了manage.php页面：
#### manage.php
```php
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<link rel="stylesheet" type="text/css" href="css/jqtree/jqtree.css">
	<link rel="stylesheet" type="text/css" href="css/manage-style.css">
	<link rel="stylesheet" type="text/css" href="css/artDialog/ui-dialog.css">
	<link rel="stylesheet" type="text/css" href="css/smartMenu/smartMenu.css">
	<script type="text/javascript" src="js/jquery-2.2.1.min.js"></script>
	<script type="text/javascript" src="js/jquery.cookie.js"></script>
	<script type="text/javascript" src="js/artDialog/dialog-min.js"></script>
	<script type="text/javascript" src="js/smartMenu/jquery-smartMenu-min.js"></script>
	<script type="text/javascript" src="js/jqtree/tree.jquery.js"></script>
	<script type="text/javascript" src="js/form/jquery.form.min.js"></script>
	<script type="text/javascript" src="js/manage.js"></script>
	<title>FTP Tool Manage</title>
</head>
<body>
	<div id="header">
		<div id="header_userinfo">
			<div id="header_userinfo_head"> <img  src="images/user.png"> </div>
			<div id="header_userinfo_loginstate">
				<div id="header_userinfo_name"></div>
				<div id="header_userinfo_state">
					<a href="#" id="header_userinfo_exit">退出</a>
				</div>
			</div>
		</div>
	</div>

	<div id="folder">
		<div id="folderTree"></div>
		<div id="folderList">
			<div id="folderList_header">
				<div id="folderList_header_logo">
					<a href="#" title="根目录"><img src="images/home.png"/></a>
				</div>
				<div id="folderList_header_path">
				</div>
				<div id="folderList_header_back">
					<a href="#" title="上一级"><img src="images/left.png" style="width: 40px" /></a>
				</div>
				<div id="folderList_header_toolbar">
						<a id="folderList_header_toolbar_upload" href="#" ><img  src="images/upload.png"><span>上传</span></a>
						<a id="folderList_header_toolbar_newfile" href="#"><img  src="images/newfile.png"><span>新建文件</span></a>
						<a id="folderList_header_toolbar_newfolder" href="#"><img  src="images/newfolder.png"><span>新建文件夹</span></a>
				 </div>

			</div>
			<div id="folderList_opeate">
				<div id="folderList_opeate_upload">
					<div id="drop_area">将文件拖拽到此区域</div>
					<form id="form_uploadfile" action="upload.php" method="POST" enctype="multipart/form-data">
						<input id="fileupload" type="file" name="files[]" multiple/form-data hidden/>
						<button type="submit" id="bn_upload_start">开始</button>
						<button type="button" id="bn_upload_add">添加</button>
                		<button type="button" id="bn_upload_delete">删除</button>
						<button type="button" id="bn_upload_cancel">取消</button>
					</form>
                	<div id="folderList_opeate_upload_filelist">
                		<ol id="folderList_opeate_upload_filelist_ul_name">
                		</ol>
                		<ol id="folderList_opeate_upload_filelist_ul_size">
                		</ol>
                		<ol id="folderList_opeate_upload_filelist_ul_bn">
                		</ol>
                		<ol id="folderList_opeate_upload_filelist_ul_ck">
                		</ol>
                	</div>
                
                </div>
			</div>
			<div id="folderList_body">
				<ul id="folerviewlist"></ul>
			</div>
		</div>
	</div>

	
</body>
</html>
```

### 当然，在点击登录按钮之后，且进入manage.php页面之前，在这一过程中：会进行如下的很多的信息验证：
* 验证ftp的主机名（或者hostname 或者ip地址）、ftp的端口号（默认是port 21）、ftp登录用户名和ftp登录密码 等信息是否正确
	* 在此验证过程中，login.js里的很多事件会被触发：例如：登录按钮的click()事件、检测必填输入项是否有值，以决定是否启用提交按钮（input的focus事件）
#### login.js
```php
function CheckInput()
{
	var bInputState = true;
	$("input:text").each(function(index, el) 
	{
		if (el.value == "")
		{
			bInputState = false;
		}
	});

	if (bInputState)
	{
		$("#submit_button").removeAttr('disabled');
		$("#submit_button").removeClass("submit_buttonError");
		$("#submit_button").addClass("submit_buttonOk");
	}
	else
	{
		$("#submit_button").addClass('submit_buttonError');
		$("#submit_button").attr('disabled',"true");
	}
}

$(document).ready(function() 
{
	$("input").focus(function(event) 
	{
		console.log('focus');
		$("#hintText").text("登陆FTP服务器").addClass('hintOk');
		$("#hintText").removeClass('hintError');
		CheckInput();
	});

	//读取Cookie的值
	$('#ftp_host').val($.cookie('ftp_cookie[0]'));
	$('#ftp_port').val($.cookie('ftp_cookie[1]'));
	$('#ftp_user').val($.cookie('ftp_cookie[2]'));
	$('#ftp_pwd').val($.cookie('ftp_cookie[3]'));

	//检测必填输入项是否有值，以决定是否启用提交按钮
	$("input").change(function()
	{
		$("#hintText").text("登陆FTP服务器").addClass('hintOk');
		$("#hintText").removeClass('hintError');
		CheckInput();
	});
	
	//登录按钮获得焦点
	$("#submit_button").mouseenter(function()
	{		
		CheckInput();
	});
	//提交表单，登录FTP，成功则跳转至服务器返回的页面，失败则显示出错信息
	$("#submit_button").click(function(event) 
	{
		$("#hintText").text("正在登陆FPT服务器......");
		$.ajax(
		{
			url: 'web_login.php',
			type: 'POST',
			dataType: 'JSON',
			data:$('#ftp_info').serialize(),
		})
		.done(function(json)
		{
			if (json.state == 0)
			{
				$("#hintText").text("登陆成功");
				location.href = json.msg;
			}
			else
			{
				$("#hintText").text(json.msg).addClass('hintError');
			}
		});
		.error(function(json) 
		{
			$("#hintText").text('错误：服务器发生未知错误').addClass('hintError');
		});
		return false;
	});
});
```
### login.js验证成功后，就会进入web_login.php:
#### web_login.php
```php
<?php
	require_once('FTP.php');
	use badtudou\FTP as FTP;

	define('DEBUG', true);
	if (!defined('DEBUG'))
	{
		error_reporting(0);
	}

	//未提交登录表单
	if (!isset($_POST['ftp_host']))
	{
		header("Location: http:index.php"); 
		exit();
	}
	if (!isset($_SESSION))
	{
		session_start();
	}

	$ftp_host = $_POST['ftp_host'];
	$ftp_port =  (integer)$_POST['ftp_port'];
	$ftp_user = $_POST['ftp_user'];
	$ftp_pwd  = $_POST['ftp_pwd'];
	$ftpManage = new FTP($ftp_host, $ftp_port, $ftp_user, $ftp_pwd);
	$ftpManage->loginCheck();
	session_write_close();
?>
```
###如上所述， web_login.php里面引用了FTP.php，且实例化了一个FTP类的一个实例（对象），并且调用了FTP类的loginCheck()方法：
#### FTP.php
```
<?php
	namespace badtudou;
	require_once('LIB.php');
	class FTP
	{
		protected $m_host;
		protected $m_port;
		protected $m_user;
		protected $m_pwd;
		protected $m_resource;
		protected $m_ConnectState;
		protected $m_LoginState;

		public function __construct($host, $port, $user, $pwd)
		{
			$this->m_host = $host;
			$this->m_port = $port;
			$this->m_user = $user;
			$this->m_pwd  = $pwd;
			$this->m_ConnectState = false;
			$this->m_LoginState = false;
		}

		/**
		 * [析构函数，释放FTP资源]
		 */
		public function __destruct()
		{
			if ($this->getConnectState())
			{
				ftp_close($this->m_resource);
			}
		}

		/**
		 * [连接FTP服务器,成功则将连接状态设置为true]
		 */
		public function connect()
		{
			$this->m_resource = @ftp_connect($this->m_host, $this->m_port, 30);
			if ($this->m_resource)
			{
				$this->m_ConnectState = true;
			}
		}

		/**
		 * [登录FTP用户，若成功则将登录状态设置为true]
		 */
		public function login()
		{
			try
			{
				if (@ftp_login($this->m_resource, $this->m_user, $this->m_pwd) )
				{
					ftp_pasv($this->m_resource, true);
					$this->m_LoginState = true;
				}
			}
			catch(Exception $e)
			{
				throw new Exception("Error Processing Request", 1);
			}
		}

		/**
		 * [关闭FTP连接，并将连接状态设置为false]
		 */
		public function close()
		{
			ftp_close($this->m_resource);
			$this->m_LoginState = false;
		}

		/**
		 * [登录FTP用户，成功则创建会话 Cookie 索引文件，否则向客户端输出错误信息]
		 */
		function loginCheck()
		{
			$this->connect();
			if ($this->getConnectState())
			{
				$this->login();
				if ($this->getLoginState())
				{
					CreateSession($this);
					SendAnswer(0 , 'manage.php');
				}
				else
				{
					SendAnswer(2 , 'FTP用户名或密码错误');
				}
			}
			else
			{
				SendAnswer(1 , '无法连接FTP服务器');
			}
		}

		/**
		 * [获取连接状态]
		 * @return [bool] [true:已连接; false:未连接]
		 */
		public function getConnectState()
		{
			return $this->m_ConnectState;
		}

		/**
		 * [获取登录状态]
		 * @return [bool] [true:已登录; false:未登录]
		 */
		public function getLoginState()
		{
			return $this->m_LoginState;
		}

		/**
		 * [获取FTP主机地址]
		 * @return [string] [FTP主机地址]
		 */
		public function getHost()
		{
			return $this->m_host;
		}

		/**
		 * [获取FTP端口]
		 * @return [int] [FTP端口]
		 */
		public function getPort()
		{
			return $this->m_port;
		}

		/**
		 * [获取FTP用户名]
		 * @return [string] [FTP用户名]
		 */
		public function getUser()
		{
			return $this->m_user;
		}

		/**
		 * [获取FTP密码]
		 * @return [string] [FTP密码]
		 */
		public function getPWD()
		{
			return $this->m_pwd;
		}

		/**
		 * [获取当前FTP路径]
		 * @return [string] [当前FTP路径]
		 */
		public function getCurrentPath()
		{
			return ftp_pwd($this->m_resource);
		}

		/**
		 * [获取指定路径下的文件列表]
		 * @param  [string] $path [路径]
		 * @return [array]       [文件列表数组]
		 */
		public function getFileList($path)
		{
			return ftp_nlist($this->m_resource, $path);
		}

		/**
		 * [将指定路径为设置为FTP当前目录]
		 * @param  [string] $path [路径]
		 * @return [bool]       [true：成功; false:失败]
		 */
		public function changeDir($path)
		{
			return @ftp_chdir($this->m_resource, $path);
		}

		/**
		 * [获取指定文件的大小]
		 * @param  [string] $file [文件的完整路径]
		 * @return [int]       [文件的字节数]
		 */
		public function getFileSize($file)
		{

			return  ftp_size($this->m_resource, $file);
		}

		/**
		 * [在指定路径下创建文件夹]
		 * @param  [string] $path   [路径]
		 * @param  [string] $folder [文件夹名]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function createFolder($path, $folder)
		{
			if ($this->changeDir($path))
			{
				if (ftp_mkdir($this->m_resource, $folder))
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}

		/**
		 * [在指定路径下创建文件]
		 * @param  [string] $path   [路径]
		 * @param  [string] $file [文件名]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function createFile($path, $file)
		{
			if ($this->changeDir($path))
			{
				fopen($file, 'w+');
				if ( @ftp_nb_put($this->m_resource, $file, $file,  FTP_ASCII) == FTP_FINISHED)
				{
					unlink($file);
					return true;
				}
				else
				{
					unlink($file);
					return false;
				}
			}
		}

		/**
		 * [删除指定路径的文件]
		 * @param  [string] $file [文件路径]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function deleteFile($file)
		{
			return ftp_delete($this->m_resource, $file);
		}


		/**
		 * [文件重命名]
		 * @param [string] $path       [路径]
		 * @param [string] $file       [文件/文件夹]
		 * @param [string] $oldname    [旧的文件名/文件夹名]
		 * @param [string] $newname    [新的文件名/文件夹名]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function rename($path, $oldname, $newname)
		{
			if ($this->changeDir($path))
			{
				return ftp_rename($this->m_resource, $oldname, $newname);
			}

			return false;
		}

		/**
		 * [下载文件]
		 * @param  [string] $remotefile [远程文件]
		 * @param  [string] $localfile  [本地文件]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function downloadFile($remotefile, $localfile)
		{
			$ret = ftp_nb_get($this->m_resource, $localfile, $remotefile,  FTP_BINARY);
			while ($ret == FTP_MOREDATA)
			{
				$ret = ftp_nb_continue ($this->m_resource);
			}
			if ($ret != FTP_FINISHED)
			{
				return false;
			}

			return true;
		}

		/**
		 * [上传文件]
		 * @param  [string] $remotefile [远程文件]
		 * @param  [string] $localfile  [本地文件]
		 * @return [bool]         [true:成功; false:失败]
		 */
		public function uploadFile($remotefile, $localfile)
		{
			$ret = ftp_nb_put($this->m_resource, $remotefile, $localfile, FTP_BINARY);
			while ($ret == FTP_MOREDATA) 
			{
			   $ret = ftp_nb_continue($this->m_resource);
			}
			if ($ret != FTP_FINISHED) 
			{
   				return false;
   			}
   			else
   			{
   				return true;
   			}

		}
	}


?>
```
### 在调用了FTP的loginCheck()后，根据上述代码可知，进入了manage.php
manage.php的代码已经叙述过了，查看请往上翻。

# 未完，待续。。。


