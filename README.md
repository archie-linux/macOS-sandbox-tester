### Running the Program

- make sandbox_tester
- ./sandbox_tester (without any restrictions; normal execution)

<pre>
MacBook-Air-2:macOS-sandbox anish$ ./sandbox_tester 
🔒 macOS App Sandbox Test
[✅] File write succeeded!
[✅] Network connection succeeded!
</pre>

- sandbox-exec -f mac_sandbox.sb ./sandbox_tester

<pre>
MacBook-Air-2:macOS-sandbox anish$ sandbox-exec -f mac_sandbox.sb ./sandbox_tester
🔒 macOS App Sandbox Test
[⛔] File write failed: Sandbox restriction enforced. (Operation not permitted - errno: 1)
[⛔] Connection failed: Sandbox restriction enforced.
</pre>

- log show --predicate 'process == "sandbox"' --info --debug  # inspect logs

