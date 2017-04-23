for ($i = 0; $i -lt 10; $i++){
$param = ($i+1)*1000
$process = Start-Process -FilePath "D:\AVL\AVL-Tree\sln\SearchTrees\Release\SetSample.exe" -ArgumentList $param -NoNewWindow -Wait
}