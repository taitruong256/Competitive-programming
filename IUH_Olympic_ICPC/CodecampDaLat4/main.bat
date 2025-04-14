# Define the path to the file or folder
$filePath = "E:\CodecampDaLat4\dalat17.zip"

# Get the current ACL
$acl = Get-Acl -Path $filePath

# Define the username or group for which you want to set permissions
# You can use 'Everyone' to grant permissions to all users
$user = "Everyone"

# Define the permission level (FullControl in this case)
$permission = "FullControl"

# Create a new FileSystemAccessRule
$rule = New-Object System.Security.AccessControl.FileSystemAccessRule($user, $permission, "Allow")

# Add the rule to the ACL
$acl.SetAccessRule($rule)

# Set the modified ACL back to the file or folder
Set-Acl -Path $filePath -AclObject $acl