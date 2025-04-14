# .ps1
$test_count = 50                              

Write-Host "Compiling C++ files..." -ForegroundColor Yellow
g++ gen_input.cpp -o gen_input.exe
g++ t.cpp -o brute_solution.exe  # nho doi ten file .cpp 
g++ C.cpp -o solution.exe              # nho doi ten file .cpp 

if (!(Test-Path .\gen_input.exe) -or !(Test-Path .\brute_solution.exe) -or !(Test-Path .\solution.exe)) {
    Write-Host "Compilation failed!" -ForegroundColor Red
    exit
}

.\gen_input.exe 1
.\brute_solution.exe
.\solution.exe 

for ($i = 1; $i -le $test_count; $i++) {
    .\gen_input.exe $i
    $input = Get-Content "input.txt" -Raw
    .\brute_solution.exe | Out-File -Encoding ASCII "correct_output.txt"
    .\solution.exe | Out-File -Encoding ASCII "output.txt"

    $execution_time = Measure-Command {
        $output = & .\solution.exe 2>&1  
        $exit_code = $LASTEXITCODE     
    }

    if ($exit_code -ne 0) {
        Write-Host "Test $${i}: Runtime Error (Exit Code: $exit_code)" -ForegroundColor Red  # bo dau $
        Write-Host "Input: $input" -ForegroundColor Gray
        Write-Host "Error Message: $output" -ForegroundColor Red
        continue
    }

    $correct_output = Get-Content "correct_output.txt" -Raw
    $user_output = Get-Content "output.txt" -Raw

    $correct_output = $correct_output -replace '\s+', '' 
    $user_output = $user_output -replace '\s+', ''

    if ($correct_output -eq $user_output) {
        Write-Host "Test ${i}: Accepted (Execution Time: $($execution_time.TotalMilliseconds) ms)" -ForegroundColor Green   # bo dau $
    } else {
        Write-Host "Test ${i}: Wrong answer" -ForegroundColor Red   # bo dau $
        Write-Host "Input: $input" -ForegroundColor Gray
        Write-Host "Correct Output: $correct_output" -ForegroundColor Gray
        Write-Host "User Output: $user_output" -ForegroundColor Gray
    }
}