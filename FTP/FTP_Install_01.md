UBuntu16.10�°�װftp����
------------------------
### ���ȸ������Դ����֤Դ�����µģ����������ڱ�֤����ͨ��apt-get install���װftp��
	sudo apt-get update
### ��װvsftp : ʹ��sudo apt-get install vsftp���װvsftp����װ�����ҪrootȨ�ޣ�����ʹ��sudo����ʱ��ȡ��
	sudo apt-get install vsftpd
### ��װ��ftp��Ĭ���ǻ��Զ�����ftp�û��ģ�Ȼ����������ftp�û������룬���� sudo passwd ftp��Ȼ���������룬��ȷ�����롣
	sudo passwd ftp
### ����ftp�û��ļ�Ŀ¼��ʹ��sudo mkdir /home/ftp����
	sudo mkdir /home/ftp
### ����ftp��Ŀ¼��Ȩ�ޣ�������Ϊ����ֱ��ʹ�� sudo chmod 777 /home/ftp ���Ȩ������Ϊ777����Ȼ����Ը����Լ�����������á�
	sudo chmod 777 /home/ftp
### ��/etc/vsftpd.conf�����ļ�����һ�����޸ġ�ʹ�� sudo vi /etc/vsftpd.conf�������ļ��������ϲ��vim�༭��Ҳ����ʹ�����򿪡�
	sudo vi /etc/vsftpd.conf
* ��/etc/vsftpd.conf�����ļ��󣬶������ļ������ݽ���һϵ�б�Ҫ���޸ģ�
	* �������ļ��С�anonymous_enable=YES ����Ϊ ��anonymous_enable=NO�����Ƿ���������ftp����������ѡNO��
	* ȡ����������ǰ��ע�ͷ��ţ�
		* local_enable=YES���Ƿ��������û���¼��
		* write_enable=YES���Ƿ��������û�д��Ȩ�ޣ�
		* chroot_local_user=YES���Ƿ������û���������Ŀ¼��
		* chroot_list_enable=YES���Ƿ����������û���������
		* chroot_list_file=/etc/vsftpd.chroot_list�������ļ������ö���˺ţ�
![ftp_02](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
![ftp_01](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_01.png "ftp_01")
### Ȼ�󴴽�����chroot_list_file�ļ���·�� �� /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
Ȼ����/etc/vsftpd.chroot_list�ļ�����ftp�û���ftp
![ftp_03](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_03.png "ftp_03")

### ����ftp������һЩ�ļ���/home/ftpĿ¼��
* ����һ���������������ftp://localhost����ҳ��¼��
![ftp_05](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_05.png "ftp_05")
![ftp_06](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_06.png "ftp_06")
* �����������ն�������ftp localhost��Ȼ�������û���������ʵ�ֵ�¼��
![ftp_04](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_04.png "ftp_04")
* ����������Windows�£�ʹ�� "ftp:ip_address" (ip_address����UBuntu������ip��ַ)����½����UBuntu��ftp����
![ftp_11](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_11.png "ftp_11")

### �����¼ftp���ǳ���������󣬿��Խ�/etc/vsftpd.conf�����ļ���pam_service_name=vsftpd��Ϊpam_service_name=ftp�����ɽ����
![ftp_07](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_07.png "ftp_07")
### ����
[������Բο��ٶȾ��飬���������õ�](https://jingyan.baidu.com/article/7908e85c988b23af481ad2ae.html)



	
	
ubuntu�°�װvftp ��װvsftpd�󣬵�¼ftp������ʱ������ʾ���� 530 Login incorrect
==================================================
* ��������Դ��

* ˢ��Դ��sudo apt-get update

* sudo apt-get install vsftpd

* �½�"/home/uftp"Ŀ¼��Ϊ�û���Ŀ¼��"�ն˴���"������"sudo mkdir /home/uftp"-->�س�-->����"sudo ls /home"-->�س�-->��һ��uftpĿ¼��Ŀ¼�½��ɹ���

* �½��û�uftp�����������"�ն˴���"������"sudo useradd -d /home/uftp -s /bin/bash uftp"-->�س�-->�û��½��ɹ�-->����"sudo passwd uftp"����uftp�û�������-->�س�-->������������-->�س�-->�������óɹ���

* ʹ��gedit�޸������ļ�/etc/vsftpd.conf��"�ն˴���"������"sudo gedit /etc/vsftpd.conf"-->�س�-->����vsftpd.conf�ļ������ļ������:
	* userlist_deny=NO 
	* userlist_enable=YES 
	* userlist_file=/etc/allowed_users
	* seccomp_sandbox=NO -->ʹ�ļ��е�"local_enable=YES"-->���档
![ftp_08](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_08.png "ftp_08")
!["ftp_02"](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
### Ȼ�������� userlist_file=/etc/allowed_users �´��� /etc/allowed_users
	touch /etc/allowed_users
	sudo chmod 777 /etc/allowed_users
	��/etc/allowed_users�����ftp�û���ftp

![ftp_09](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_09.png "ftp_09")

* ʹ��gedit�鿴/etc/ftpusers�ļ��е����ݴ�"�ն˴���"������"sudo gedit /etc/ftpusers"-->�س�-->������ļ��󣬿�һ����û��uftp����û��������û�У���ֱ���˳�������о�ɾ��uftp,
��Ϊ����ļ��м�¼���ǲ��ܷ���FTP���������û��嵥����ȥ��root��


### ����
[������ν�� "530 Login incorrect" ��ftp��¼���⣬���Բο�������](http://www.cnblogs.com/bqx619/p/5021458.html)




�������������ǽ��������� O(��_��)Oû�����϶��ǻ����Ĵ��������������������⣺ʹ��PHP��API��¼FTP�����������ļ����в�����
-----------------------------
### ����ͼ��
���ҵ�UBuntu�ϵ�����ip��ַ������ʾ��
![ftp_10](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_10.png "ftp_10")
ʹ��PHP�ĵ�¼����������ʾ��
![ftp_12](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_12.png "ftp_12")
![ftp_13](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_13.png "ftp_13")
![ftp_14](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_14.png "ftp_14")
![ftp_15](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_15.png "ftp_15")

### PHP���������Ŀ¼��Ӧ��ʱ������ӵģ�
![ftp_16](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_16.png "ftp_16")
### ���ȣ����ǽ������ҳ����index.phpҳ�棺
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
			<p id="hintText" class="hintOk">��½FTP������</p>
			<p><input type="text" id="ftp_host" name="ftp_host" placeholder="����/IP��ַ"></input></p>
			<p><input type="text" id="ftp_port" name="ftp_port" placeholder="�˿�"></input></p>
			<p><input type="text" id="ftp_user" name="ftp_user" placeholder="�û���"></input></p>
			<p><input type="password" id="ftp_pwd" name="ftp_pwd" placeholder="����"></input></p>
			<p><input type="submit" id="submit_button" class="submit_buttonOk" value="������½"></input></p>
		</form>
	</div>
</body>
</html>
```

### ���������������Ϣ���ҳɹ���¼UBuntu�ϵ�FTP server�����ǽ�����manage.phpҳ�棺
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
					<a href="#" id="header_userinfo_exit">�˳�</a>
				</div>
			</div>
		</div>
	</div>

	<div id="folder">
		<div id="folderTree"></div>
		<div id="folderList">
			<div id="folderList_header">
				<div id="folderList_header_logo">
					<a href="#" title="��Ŀ¼"><img src="images/home.png"/></a>
				</div>
				<div id="folderList_header_path">
				</div>
				<div id="folderList_header_back">
					<a href="#" title="��һ��"><img src="images/left.png" style="width: 40px" /></a>
				</div>
				<div id="folderList_header_toolbar">
						<a id="folderList_header_toolbar_upload" href="#" ><img  src="images/upload.png"><span>�ϴ�</span></a>
						<a id="folderList_header_toolbar_newfile" href="#"><img  src="images/newfile.png"><span>�½��ļ�</span></a>
						<a id="folderList_header_toolbar_newfolder" href="#"><img  src="images/newfolder.png"><span>�½��ļ���</span></a>
				 </div>

			</div>
			<div id="folderList_opeate">
				<div id="folderList_opeate_upload">
					<div id="drop_area">���ļ���ק��������</div>
					<form id="form_uploadfile" action="upload.php" method="POST" enctype="multipart/form-data">
						<input id="fileupload" type="file" name="files[]" multiple/form-data hidden/>
						<button type="submit" id="bn_upload_start">��ʼ</button>
						<button type="button" id="bn_upload_add">���</button>
                		<button type="button" id="bn_upload_delete">ɾ��</button>
						<button type="button" id="bn_upload_cancel">ȡ��</button>
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

### ��Ȼ���ڵ����¼��ť֮���ҽ���manage.phpҳ��֮ǰ������һ�����У���������µĺܶ����Ϣ��֤��
* ��֤ftp��������������hostname ����ip��ַ����ftp�Ķ˿ںţ�Ĭ����port 21����ftp��¼�û�����ftp��¼���� ����Ϣ�Ƿ���ȷ
	* �ڴ���֤�����У�login.js��ĺܶ��¼��ᱻ���������磺��¼��ť��click()�¼����������������Ƿ���ֵ���Ծ����Ƿ������ύ��ť��input��focus�¼���
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
		$("#hintText").text("��½FTP������").addClass('hintOk');
		$("#hintText").removeClass('hintError');
		CheckInput();
	});

	//��ȡCookie��ֵ
	$('#ftp_host').val($.cookie('ftp_cookie[0]'));
	$('#ftp_port').val($.cookie('ftp_cookie[1]'));
	$('#ftp_user').val($.cookie('ftp_cookie[2]'));
	$('#ftp_pwd').val($.cookie('ftp_cookie[3]'));

	//�������������Ƿ���ֵ���Ծ����Ƿ������ύ��ť
	$("input").change(function()
	{
		$("#hintText").text("��½FTP������").addClass('hintOk');
		$("#hintText").removeClass('hintError');
		CheckInput();
	});
	
	//��¼��ť��ý���
	$("#submit_button").mouseenter(function()
	{		
		CheckInput();
	});
	//�ύ������¼FTP���ɹ�����ת�����������ص�ҳ�棬ʧ������ʾ������Ϣ
	$("#submit_button").click(function(event) 
	{
		$("#hintText").text("���ڵ�½FPT������......");
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
				$("#hintText").text("��½�ɹ�");
				location.href = json.msg;
			}
			else
			{
				$("#hintText").text(json.msg).addClass('hintError');
			}
		});
		.error(function(json) 
		{
			$("#hintText").text('���󣺷���������δ֪����').addClass('hintError');
		});
		return false;
	});
});
```
### login.js��֤�ɹ��󣬾ͻ����web_login.php:
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

	//δ�ύ��¼��
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
###���������� web_login.php����������FTP.php����ʵ������һ��FTP���һ��ʵ�������󣩣����ҵ�����FTP���loginCheck()������
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
		 * [�����������ͷ�FTP��Դ]
		 */
		public function __destruct()
		{
			if ($this->getConnectState())
			{
				ftp_close($this->m_resource);
			}
		}

		/**
		 * [����FTP������,�ɹ�������״̬����Ϊtrue]
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
		 * [��¼FTP�û������ɹ��򽫵�¼״̬����Ϊtrue]
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
		 * [�ر�FTP���ӣ���������״̬����Ϊfalse]
		 */
		public function close()
		{
			ftp_close($this->m_resource);
			$this->m_LoginState = false;
		}

		/**
		 * [��¼FTP�û����ɹ��򴴽��Ự Cookie �����ļ���������ͻ������������Ϣ]
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
					SendAnswer(2 , 'FTP�û������������');
				}
			}
			else
			{
				SendAnswer(1 , '�޷�����FTP������');
			}
		}

		/**
		 * [��ȡ����״̬]
		 * @return [bool] [true:������; false:δ����]
		 */
		public function getConnectState()
		{
			return $this->m_ConnectState;
		}

		/**
		 * [��ȡ��¼״̬]
		 * @return [bool] [true:�ѵ�¼; false:δ��¼]
		 */
		public function getLoginState()
		{
			return $this->m_LoginState;
		}

		/**
		 * [��ȡFTP������ַ]
		 * @return [string] [FTP������ַ]
		 */
		public function getHost()
		{
			return $this->m_host;
		}

		/**
		 * [��ȡFTP�˿�]
		 * @return [int] [FTP�˿�]
		 */
		public function getPort()
		{
			return $this->m_port;
		}

		/**
		 * [��ȡFTP�û���]
		 * @return [string] [FTP�û���]
		 */
		public function getUser()
		{
			return $this->m_user;
		}

		/**
		 * [��ȡFTP����]
		 * @return [string] [FTP����]
		 */
		public function getPWD()
		{
			return $this->m_pwd;
		}

		/**
		 * [��ȡ��ǰFTP·��]
		 * @return [string] [��ǰFTP·��]
		 */
		public function getCurrentPath()
		{
			return ftp_pwd($this->m_resource);
		}

		/**
		 * [��ȡָ��·���µ��ļ��б�]
		 * @param  [string] $path [·��]
		 * @return [array]       [�ļ��б�����]
		 */
		public function getFileList($path)
		{
			return ftp_nlist($this->m_resource, $path);
		}

		/**
		 * [��ָ��·��Ϊ����ΪFTP��ǰĿ¼]
		 * @param  [string] $path [·��]
		 * @return [bool]       [true���ɹ�; false:ʧ��]
		 */
		public function changeDir($path)
		{
			return @ftp_chdir($this->m_resource, $path);
		}

		/**
		 * [��ȡָ���ļ��Ĵ�С]
		 * @param  [string] $file [�ļ�������·��]
		 * @return [int]       [�ļ����ֽ���]
		 */
		public function getFileSize($file)
		{

			return  ftp_size($this->m_resource, $file);
		}

		/**
		 * [��ָ��·���´����ļ���]
		 * @param  [string] $path   [·��]
		 * @param  [string] $folder [�ļ�����]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
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
		 * [��ָ��·���´����ļ�]
		 * @param  [string] $path   [·��]
		 * @param  [string] $file [�ļ���]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
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
		 * [ɾ��ָ��·�����ļ�]
		 * @param  [string] $file [�ļ�·��]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
		 */
		public function deleteFile($file)
		{
			return ftp_delete($this->m_resource, $file);
		}


		/**
		 * [�ļ�������]
		 * @param [string] $path       [·��]
		 * @param [string] $file       [�ļ�/�ļ���]
		 * @param [string] $oldname    [�ɵ��ļ���/�ļ�����]
		 * @param [string] $newname    [�µ��ļ���/�ļ�����]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
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
		 * [�����ļ�]
		 * @param  [string] $remotefile [Զ���ļ�]
		 * @param  [string] $localfile  [�����ļ�]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
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
		 * [�ϴ��ļ�]
		 * @param  [string] $remotefile [Զ���ļ�]
		 * @param  [string] $localfile  [�����ļ�]
		 * @return [bool]         [true:�ɹ�; false:ʧ��]
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
### �ڵ�����FTP��loginCheck()�󣬸������������֪��������manage.php
manage.php�Ĵ����Ѿ��������ˣ��鿴�����Ϸ���

# δ�꣬����������


