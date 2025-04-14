# Nho thay {i} thanh {i}
$test_count = 20                              

Write-Host "Compiling C++ files..." -ForegroundColor Yellow
g++ gen_input.cpp -o gen_input.exe
g++ brute_solution.cpp -o brute_solution.exe  
g++ C2.cpp -o solution.exe              

if (!(Test-Path .\gen_input.exe) -or !(Test-Path .\brute_solution.exe) -or !(Test-Path .\solution.exe)) {
    Write-Host "Compilation failed!" -ForegroundColor Red
    exit
}

for ($i = 0; $i -le $test_count; $i++) {
    $input_file = "test_${i}_input.txt"
    $correct_file = "test_${i}_output_correct.txt"
    $output_file = "test_${i}_output_user.txt"

    .\gen_input.exe $i > $input_file
    $input = Get-Content $input_file -Raw

    Get-Content $input_file | .\brute_solution.exe > $correct_file

    if ($i -eq 0) {
        Write-Host "Running warm-up test 0..."
        Get-Content $input_file | .\solution.exe > $output_file
        continue
    }

    $execution_time = Measure-Command {
        Get-Content $input_file | .\solution.exe > $output_file 2>&1
        $exit_code = $LASTEXITCODE     
    }

    if ($exit_code -ne 0) {
        Write-Host "Test ${i}: Runtime Error (Exit Code: $exit_code)" -ForegroundColor Red
        Write-Host "Input: $input" -ForegroundColor Gray
        Write-Host "Error Message:" -ForegroundColor Red
        Get-Content $output_file | ForEach-Object { Write-Host $_ -ForegroundColor Red }
        continue
    }

    $correct_output = Get-Content $correct_file -Raw
    $user_output = Get-Content $output_file -Raw

    $correct_output = $correct_output -replace '\s+', '' 
    $user_output = $user_output -replace '\s+', ''

    if ($correct_output -eq $user_output) {
        Write-Host "Test ${i}: Accepted (Execution Time: $($execution_time.TotalMilliseconds) ms)" -ForegroundColor Green
    } else {
        Write-Host "Test ${i}: Wrong answer" -ForegroundColor Red
        Write-Host "Input: $input" -ForegroundColor Gray
        Write-Host "Correct Output: $correct_output" -ForegroundColor Gray
        Write-Host "User Output: $user_output" -ForegroundColor Gray
    }
}