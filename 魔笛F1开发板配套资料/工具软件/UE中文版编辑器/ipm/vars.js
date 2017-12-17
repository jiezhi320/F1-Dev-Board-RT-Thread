var langStr = 'ch';
var ueNewPrice = "$49.95";
var ueUpgradePrice = "$24.95";
var ueUcBundleNewPrice = "$69.95";      //new bundle cost
var ueUcBundleRetailPrice = "$89.90";   //bundle retail price
var ueUCBundleYouSavePercentage = "50% on UC";
var ueUpgradeToUeUcBundlePrice = "$44.95";
var strReminderText = '剩余日子:';

var strTopRightBlockContent = 
    '<p class="register_title">注册</p>'+ 
    '<p><img src="images/uebox_sm.gif" alt="UltraEdit" border="0" class="uebox" />注册费只是: <span class="price" id="ueNewPrice">$49.95</span></p>'+ 
    '<a href="#" onClick="purchaseLink(\'BuyUE\', langStr); return false;" target="_blank"><p class="buy_button">购买</p></a>'+ 
    '<p class="upgrade_text">升级: <span class="price" id="ueUpgradePrice">$24.95</span></p>'+ 
    '<a href="#" onClick="purchaseLink(\'UpgradeUE\', langStr); return false;" target="_blank"><p class="upgrade_button">升级</p></a>';
                  
var strBottomRightBlockContent = 
    '<p class="register_title">UE/UC </p>'+ 
    '<p><img src="images/ue_uc_box.gif" alt="UltraEdit UltraCompare Bundle" border="0" class="bundlebox" />两者注册费只是: <span class="price" id="ueUcBundleNewPrice">$69.95</span></p>'+ 
    '<a href="#" onClick="purchaseLink(\'BuyUEUCBundle\', langStr); return false;" target="_blank"><p class="buy_button">购买</p></a>'+
    '<p class="save_on_uc_text">Save 50% on UC!</p> ';

var strHeaderSubText= 
    '<h2>这个是没有注册的软件。 </h2>'+
    '<p>您是利用试用版本来使用这个软件。 </p>';
    
var strStdTopHeadline = 'UltraEdit 试用版本提示';
var strHurryTopHeadline = '您的试用版本已经过期了...';
var strExpiredTopHeadline = '啊!您的试用版本已经期满了';

                          
// ----- DIALOG CONTENT ---------//     
var defaultContent =
		'<h2>谢谢您评估 UltraEdit</h2>'+
		'<p class="subtext">您是利用试用版本来使用这个软件。</p>'+
		'<p>这个是没有注册的软件。如果您想继续使用这个软件，请购买授权。 </p>'+
		'<p><a href="#" onClick="openLink(\'http://www.ultraedit.com/redirects/registration/ch/ue_register.html\'); return false;" target="_blank">单击这里注册 UltraEdit</a></p>'+
		'<p style="clear: all"><b>Visa, MasterCard, Amex accepted</b></p>'+
		'<p>哲想方案（北京）科技有限公司(IDM 中国)<br />北京市海淀区西三环北路50号院<br />H豪柏大厦B1座606室, 邮编 100048<br />傳真: 86-10-68413628<br />电邮: <a href="mailto:sales@ultraedit.cn" target="_blank">sales@ultraedit.cn</a></p>'+
		'<p><a href="#" onClick="openLink(\'http://www.ultraedit.com/company/contact_us.html\'); return false;" target="_blank">如果有问题，请跟我们联络</a> </p>';


var welcomeContent =
		'<h2>谢谢您评估 UltraEdit</h2>'+
		'<p>利用 IDM 用户社区资源中心最大化您的生产力 - 包括支持、下载、新闻等...</p>'+
		'<div class="powertips">'+
		'<p><span class="resource_title">力量提示/教程</span><br />'+
		'"How-tos" 是给最新版本的功能，和现有功能的深入教程。</p>'+
		'</div>'+
		'<div class="tech_support">'+
		'<p><span class="resource_title">技术支持</span><br />'+
		'有问题?  有答案!  利用您的技术资源令 IDM 软件为您服务。</p>'+
		'</div>'+
		'<div class="forums">'+
		'<p><span class="resource_title">用户对用户论坛</span><br />'+
		'参加论坛跟 IDM 产品的爱好者分享 - 分享技巧，得到意见等。</p>'+
		'</div>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/resources.html\'); return false;" target="_blank">访问资源中心</a></p>';


var benefitsContent =
    '<h2>注了册的好处</h2>'+ 
    '<div class="benefits">'+ 
    '<p><span class="subtext">为您的问题解答 - 终身支持</span><br />'+ 
    '世界级的技术支持 - 标准反应时间: 30 分钟或更少。</p>'+ 
    '<p><span class="subtext">一年免费升级</span><br />'+ 
    '注册容许您一年的升级，包括重要和次要的版本。</p>'+ 
    '<p><span class="subtext">社区好处</span><br />'+ 
    '超过二百万用户、丰富网上资源、力量提示、用户主导开发模式、月刊和论坛等 </p>'+ 
    '<div class="bonus">'+       
      '<p><span class="subtext">用户基础的授权!</span><br />'+ 
      '拥有膝上型轻便电脑或额外 PC? 注册可以容许你安装在多个电脑上 - 条件是你是唯一用软件的用户。</p>'+ 
    '</div>'+ 
    '</div> <!-- end benefits -->';


var findAndReplaceContent =
		'<img src="images/find_dialog.gif" alt="Find Dialog" border="0" class="tip_screenshot" />'+
		'<h2>寻找/替换</h2>'+
		'<p class="subtext">这个强大的功能让您寻找/替换在一个文件的文字，多的文件等</p>'+
		'<p>在寻找菜单中存取寻找/替换或利用热键 - CTRL+F 就是寻找，CTRL+R 就是替换。您可以利用在文件的功能的寻找/替换，它可以让您在目录中寻找/替换。</p>'+
		'<p>其中高级的寻找/替换选项包括正则表达式、文件寻找/替换、列寻找等。 </p>'+
		'<p class="powertip_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/find_replace.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var projectsContent =
		'<img src="images/projects_dialog.gif" alt="Projects" border="0" class="tip_screenshot" />'+
		'<h2>项目</h2>'+
		'<p class="subtext">结合和管理您项目的相关文件和目录。</p>'+
		'<p>为什么要用项目? 无论您是开发软件，管理资料文件或注意 "to-dos" 动向，项目给您一个方便的方法结合和管理您的文件。</p>'+
		'<p>还有，项目被结合在 UltraEdit 的框架上，令执行一般工做很容易 - 如在项目文件内做取代。单击以下了解如何建立项目，如何增加/删除项目文件等!</p>'+
		'<p class="powertip_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/group_files_and_folders_with_projects.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var diffFilesAndFoldersContent =
		'<img src="images/uc_dialog.gif" alt="Compare files and folders" border="0" class="tip_screenshot" />'+
		'<h2>分别文件/目录</h2>'+
		'<p class="subtext">利用 UltraCompare，比较文件和目录是件很容易的事！</p>'+
		'<p>UltraEdit 跟 UltraCompare Lite 一起，它们可以做简单的分别工做，如比较文件和目录和识别分别。</p>'+
		'<p>但是，如果您升级到 UltraCompare Professional，您可以享受一个完整的功能集。UltraCompare Professional 包括 2途径和 3途径比较、合并分别、打包存档比较、外观、忽略选项、对话、字文件比较等</p>'+
		'<p class="powertip_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/compare_files_folders.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var columnModeContent =
		'<img src="images/column_mode_icon.gif" alt="Column Mode" border="0" class="tip_screenshot" />'+
		'<h2>Column Mode</h2>'+
		'<p class="subtext">列模式... UltraEdit 其中一个最方便的功能! '+
		'<p>Column Mode changes the way you select text in the editor allowing you to select columns and rows of text as opposed to only selecting rows. </p>'+
		'<p>想试列模式?  只是需要利用 ALT+C 向内和向外转换列模式 (或从工具栏/菜单) 和垂直地/水平地选取文字。 </p>'+
		'<p>列模式可以用来格式化，如 左/右对齐、插入数字、加列等... </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/column_mode.html\'); return false;" target="_blank">单击这里了解更多</a></p>';



var bookmarksContent =
		'<img src="images/bookmarks_icon.gif" alt="Bookmarks" border="0" class="tip_screenshot" />'+
		'<h2>标签</h2>'+
		'<p class="subtext">利用标签简化您的工作流程...</p>'+
		'<p style="clear: both">标签是一个方便的方法“保存”文件和编码重要的位置。如果您需要做标签，按 CTRL + F2；跳到下一个标签，按 F2；跳到上一个标签，按 ALT + F2。</p>'+
		'<p>您可以用标签检视器快速检视（和导航到）在活跃文件内的标签， 和在所有打开的文件的标签。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/bookmarks.html\'); return false;" target="_blank">单击这里更多</a></p>';


var addWordfileContent =
		'<img src="images/add_wordfile_icon.gif" alt="Add a Wordfile" border="0" class="tip_screenshot" />'+
		'<h2>赠加一个字文件</h2>'+
		'<p class="subtext">用赠加一个字文件来增加其它语言的语法突出</p>'+
		'<p>UltraEdit 支持 12 语言，但是您可以更改字文件来增加或删除语言。</p>'+
		'<p>由于 UltraEdit 的语法突出是可以设置的 (根据字文件) 您可以从我们的网站上的众多字文件中为您的语言增加语法突出支持。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/add_a_wordfile.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var htmlPreviewContent =
		'<img src="images/browser_preview_icon.gif" alt="HTML Preview" border="0" class="tip_screenshot" />'+
		'<h2>HTML 预览</h2>'+
		'<p class="subtext">利用综合浏览器预览检查您的 HTML</p>'+
		'<p>什么可以让编辑 HTML 更容易?  方便存取 HTML 预览。如果您在编码 html，您是绝对需要它...</p>'+
		'<p>简单地编辑 html 文件，从主要的工具栏或从检视菜单中转换“浏览器预览”。如果您完成预览您的改动，转换浏览器预览到关状态... 很容易!</p> '+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/integrated_html_preview.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var environmentsContent =
		'<img src="images/environment_icon.gif" alt="Environments" border="0" class="tip_screenshot" />'+
		'<h2>环境</h2>'+
		'<p class="subtext">利用 TaskMatch 环境转换工做S</p>'+
		'<p>什么是环境? 环境可以容许您快速地转换编辑版面，以便您可以根据您的需要转换菜单、工具栏、可收藏的窗、定做模板等。</p>'+
		'<p>环境是一个非常好的功能，因为它们可以让您转换配置/选项。作法只是单击，不用一个一个配置。 不喜欢默认环境? 没有问题，您可以自己定做或建立一个!</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/environments.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var cssStyleBuilderContent =
		'<img src="images/style_builder.gif" alt="CSS style builder" border="0" class="tip_screenshot" />'+
		'<h2>CSS 类型建立者</h2>'+
		'<p class="subtext">利用 CSS 类型建立者快速和容易地建立您的样式表</p>'+
		'<p>CSS 类型建立者可以建立背景、字形/文字和移动/定位。您可一设置价值，然后按 “确定”把它们插入活跃文件!</p>'+
		'<p>开动 CSS 类型建立者，在工具栏的工具按“类型建立者”。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/css_style_builder.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var diffFilesAndFoldersContent =
		'<img src="images/uc_dialog.gif" alt="Compare files and folders" border="0" class="tip_screenshot" />'+
		'<h2>分别文件/目录</h2>'+
		'<p class="subtext">利用 UltraCompare，比较文件和目录是件很容易的事！</p>'+
		'<p>UltraEdit 跟 UltraCompare Lite 一起，它们可以做简单的分别工做，如比较文件和目录和识别分别。</p>'+
		'<p>但是，如果您升级到 UltraCompare Professional，您可以享受一个完整的功能集。UltraCompare Professional 包括 2途径和 3途径比较、合并分别、打包存档比较、外观、忽略选项、对话、字文件比较等</p>'+
		'<p class="powertip_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/compare_files_folders.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var mergeDifferencesContent =
		'<img src="images/uc_merge_icon.gif" alt="Merge files and folders" border="0" class="tip_screenshot" />'+
		'<h2>合并差别</h2>'+
		'<p class="subtext">利用 UltraCompare Professional 同步文件的差别</p>'+
		'<p>UltraCompare Pro 不单支持两路和三路比较，它亦可以支持合并差别!</p>'+
		'<p>UltraCompare Professional 有一批合并的选项，它给您处理文件和目录的差别。一点击就可以合并差别。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultracompare/block_line_mode_merge.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var findAndReplaceInFilesContent =
		'<img src="images/replace_in_files_icon.gif" alt="Replace in Files" border="0" class="tip_screenshot" />'+
		'<h2>文件的寻找/替换</h2>'+
		'<p class="subtext">在整个目录结构内利用寻找/替换...</p>'+
		'<p>在文件选项的文件/替换的寻找，您可以在寻找菜单中找到。这些强大的寻找选项容许您一个目录中在不同文见寻找字串或文字。</p>'+
		'<p>利用文件的文件/替换的寻找，您可以寻找/替换和寻找字目录、项目/喜爱文件、指定文件类型、忽略的子目录名称等。 </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/find_replace.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var sortContent =
		'<img src="images/sort_icon.gif" alt="Sort" border="0" class="tip_screenshot" />'+
		'<h2>排序您的资料</h2>'+
		'<p class="subtext">您是否知道您可以把文本的资料排序?</p>'+
		'<p>UltraEdit 的排序将您的资料整理到容易阅读和处理! 排序可以帮助您阅读记录文件，排序文件资料库的域或删除重复的条目/行。</p>'+
		'<p>强大的排序引擎容许您在几个 “键”（列）排序文件资料。您可以根据基本或高级选项排序。 单击以下了解更多排序。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/advanced_column_based_sort.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var linkLocalAndRemoteContent =
		'<img src="images/link_local_remote.gif" alt="Link Your Local and Remote Directories" border="0" class="tip_screenshot" />'+
		'<h2>连接本地/远端目录</h2>'+
		'<p class="subtext">利用项目和 FTP/SFTP 连接一个目录到您的现场/远端目录!</p>'+
		'<p>项目是很有用，因为它们容许您组织和聚合您的文件和目录。   </p>'+
		'<p>当项目可以用来组织和聚合文件和目录，它们亦可以容易地执行一般工作。您可以利用 FTP/SFTP 户口连接您的项目，它可以让您连接本地/远端目录 - 令上载、下载和同步操作不费吹灰之力!</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/sync_local_to_remote.html\'); return false;" target="_blank">单击这里了解更多。</a></p>';


var ftpSftpContent =
		'<img src="images/ftp_dialog.gif" alt="FTP Browser" border="0" class="tip_screenshot" />'+
		'<h2>FTP/SFTP 支持</h2>'+
		'<p class="subtext">利用 FTP/SFTP 在远端服务器上存取文件 &amp; 目录。</p>'+
		'<p>无论您是利用 UltraEdit 来开发或基本文字编辑，您需要 FTP/SFTP。</p>'+
		'<p>装配您的 FTP 户口和利用内置 FTP/SFTP 开和保存选项和 FTP 浏览。</p>'+
		'<p>您需要比较什么文件/目录在服务器上改变。没有问题，只是利用 UC Pro 的内置 FTP/SFTP 比较。</p>'+
		'<p class="powertip_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/configure_ftp.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var scriptingContent =
		'<img src="images/scripting_icon.gif" alt="Scripting" border="0" class="tip_screenshot" />'+
		'<h2>脚本</h2>'+
		'<p class="subtext">令工作更智能... 利用脚本自动化您的工作。</p>'+
		'<p>脚本结合 JavaScript 的灵活性和 UltraEdit 编辑环境的强大力量，这个给您一个动态的方法自动化您的工作。 您是否想了解更多脚本?  说明书提供所有脚本的指令和属性。</p>'+
		'<p>在编写脚本后，在脚本菜单载入脚本列表。如果您想了解更多脚本 单击以下的连结了解 UltraEdit 的脚本引擎的基本。 </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/scripting_engine_tutorial.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var templatesContent =
		'<img src="images/templates.gif" alt="templates" border="0" class="tip_screenshot" />'+
		'<h2>模板</h2>'+
		'<p class="subtext">创建和保存常常用的模板文字。</p>'+
		'<p>单击创建自定的模板和插入经常用的编码和问本等到您的文件。</p>'+
		'<p>您可以创建只包含文字的简单模板，您亦可以包含模板动态变数，日期、时间、文件名称等！ </p>'+
		'<p>您可以在先进菜单创建/修改您的模板。  </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/custom_templates.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var encryptDecryptContent =
		'<img src="images/encrypt.gif" alt="SSH/Telnet" border="0" class="tip_screenshot" />'+
		'<h2>加密/解密您的文件</h2>'+
		'<p class="subtext">利用内置加密保护敏感/专利的的资料。</p>'+
		'<p>UltraEdit 的内置加密功能提供了一个快速和容易的方法来加密/解密您的敏感资料 - 容许您安全保护您的敏感资料。 把一个文件加密，在档案菜单中选择加密选项就可以啦。</p>'+
		'<p>还有，UltraEdit 结合 UltraSentry 可以把加密后的原本文件删除。UltraEdit 内置的加密和UltraSentry 的安全删除提供了一个最终的方案保护您的敏感的资料。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/encrypt_decrypt_text_files.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var sshTelnetContent =
		'<img src="images/telnet.gif" alt="SSH/Telnet" border="0" class="tip_screenshot" />'+
		'<h2>SSH/Telnet</h2>'+
		'<p class="subtext">执行内置Telnet/SSH 命令行的行动!</p>'+
		'<p style="clear: both">UltraEdit 提供一个方便的 SSH/Telnet 控制台容许您存取服务器和执行命令行行动。您可以不离开编辑器而执这个行动！</p>'+
		'<p>Telnet/SSH 控制台可以是一个在编辑框的固定的 (docked) 窗或浮动 (undocked) 窗。</p>			'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/ssh_telnet.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var searchFavoritesContent =
		'<img src="images/search_favorites.gif" alt="Search favorites" border="0" class="tip_screenshot" />'+
		'<h2>搜索喜爱</h2>'+
		'<p class="subtext">您是否经常使用同一个搜索和替换的字串... 如果是这样，您需要搜索喜爱。</p>'+
		'<p>搜索和替换喜爱功能容许您储存经常用的搜索和替换字串。"编辑 搜索和替换喜爱" 对话给您一个方便的方法处理搜索和替换喜爱。</p>'+
		'<p>增加一个喜爱，简单地打开搜索或替换对话框，单击星形图标和选择 "加到喜爱" 选项。以后，您的搜索/替换字串会在您需要的时候出现!</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/search_replace_favorites.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var macroContent =
		'<img src="images/macro_icon.gif" alt="Macro" border="0" class="tip_screenshot" />'+
		'<h2>Macros</h2>'+
		'<p class="subtext">如何编写强大的 Macro</p>'+
		'<p>什么是 Macro?  Macros 最主要是容许您记录一系列的指令和键击，然后把它播放。 </p>'+
		'<p style="clear: both">当您自己可以编写 Macros，最容易的方法是让 UltraEdit 为您服务。其中 UltraEdit 的一个强大功能是记录、创建和播放 Macros。 </p>'+
		'<p>记录一个 Macro，利用在 Macro 菜单的快速记录/记录 指令。   </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/writing_a_powerful_macro.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var spellCheckerContent =
		'<img src="images/spell_check.gif" alt="Check your spelling" border="0" class="tip_screenshot" />'+
		'<h2>拼写检查器</h2>'+
		'<p class="subtext">担心拼错字?  </p>'+
		'<p>UltraEdit 带有 100,000 个单词的拼写检查器，支持的语种包括英语（美国）、英语（英国）、荷兰语、芬兰语、法语、德语、匈牙利语、意大利语、西班牙语和瑞典语等。</p>'+
		'<p>您可以在编辑菜单下开动拼写检查器，它会检查您选的文字或整篇 (如果没有文被选).</p>'+
		'<p>您可以在编写的时后利用实时的拼字功能。 </p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/spell_check.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


var keyboardShortcutContent =
		'<img src="images/key_mapping.gif" alt="Keyboard Shortcuts" border="0" class="tip_screenshot" />'+
		'<h2>键盘捷径</h2>'+
		'<p class="subtext">定做键盘捷径把生产力最大化。</p>'+
		'<p>在试用的时后您会发现，所有 UltraEdit 的东西都是可以定做和设置的。UltraEdit 设计为完全自主性是因为它想给您日常文本编辑的所有需要。</p>'+
		'<p>记住！UltraEdit 让您改变/扭拧菜单热门键和键变换，以便适合您的要求。</p>'+
		'<p class="resource_link"><a href="#" onClick="openLink(\'http://www.ultraedit.com/support/tutorials_power_tips/ultraedit/keymapping.html\'); return false;" target="_blank">单击这里了解更多</a></p>';


// ----- END DIALOG CONTENT ---------//

// ---- START RIGHT/LEFT CONTENT ----//

var rightSideContent =
    '<img src="images/ue_uc_box_big.gif" alt="UltraEdit UltraCompare Bundle Box" border="0" class="ue_uc_box_big" />'+ 
		'<h2>UE/UC Bundle</h2>'+ 
		'<p class="ue_uc_bundle_offer">零售价: <span class="retail_price" id="ueUcBundleRetailPrice">$89.90</span><br />'+ 
			'您的价格: <span class="price" id="ueUcBundleNewPrice">$69.95</span><br />'+ 
			'您的折扣: <span class="you_save" id="ueUCBundleYouSavePercentage">$15</span>'+ 
		'</p>'+ 
    '<p style="clear: both">UltraEdit/UltraCompare 是一个完全综合的完整文本编辑方案。 购买 UE/UC 方案，省 UC 的 50%!</p>'+     
	  '<div class="register_upgrade_container">'+ 
	  '<div class="best_value">最好价格</div>' +
	  	'<div class="register">'+ 
				'<p class="register_text">两者注册 <span class="price" id="ueUcBundleNewPrice">$69.95</span></p>'+ 
				'<a href="#" onClick="purchaseLink(\'BuyUEUCBundle\', langStr); return false;" target="_blank"><p class="buy_button">购买</p></a>'+ 
			'</div>'+ 
			'<div class="upgrade">'+ 
				'<p class="register_text">UE 升级 + UC <span class="price" id="ueUpgradeToUeUcBundlePrice">$44.95</span></p>'+ 
				'<a href="#" onClick="purchaseLink(\'UpgradeUE2UEUCBundle\', langStr); return false;" target="_blank"><p class="buy_button">升级</p></a>'+ 
		'</div>';

var leftSideContent =
    '<img src="images/uebox_big.gif" alt="UltraEdit Box" border="0" class="uebox_big" />'+ 
    '<h2>UltraEdit</h2>'+ 
    '<p>销量第一，功能最强，物超所值的文本编辑器</p>'+
		'<div class="bonus" style="clear: both">'+       
      '<p><span class="subtext">User-Based Licensing!</span><br />'+ 
      '拥有膝上型轻便电脑或额外 PC? 注册可以容许你安装在多个电脑上*.</p>'+ 
    '</div>'+ 
    '<div class="register_upgrade_container">'+ 
    '<div class="register">'+ 
    '<p class="register_text">注册 <span class="price" id="ueNewPrice">$49.95</span></p>'+ 
    '<a href="#" onClick="purchaseLink(\'BuyUE\', langStr); return false;" target="_blank"><p class="buy_button">购买</p></a>'+ 
    '</div>'+ 
    '<div class="upgrade">'+ 
    '<p class="register_text">UE 升级<span class="price" id="ueUpgradePrice">$24.95</span></p>'+ 
    '<a href="#" onClick="purchaseLink(\'UpgradeUE\', langStr); return false;" target="_blank"><p class="buy_button">升级</p></a>'+ 
    '</div>';


// ---- END RIGHT/LEFT CONTENT ----//




