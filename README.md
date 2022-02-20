# Pipex

This project consists of reproducing the behavior of the [shell pipe](https://www.geeksforgeeks.org/piping-in-unix-or-linux/), redirecting STDIN and STDOUT using [pipes](https://www.geeksforgeeks.org/pipe-system-call/).<br><br>
![jisokang's so_long Score](https://badge42.herokuapp.com/api/project/ael-bekk/pipex)

### What is Pipex?
Pipex is an individual project at [42](42sp.org.br) that requires us to create a program that simulates the behavior of the [shell pipe](https://www.geeksforgeeks.org/piping-in-unix-or-linux/), receiving a file or reading from the [STDIN](https://en.wikipedia.org/wiki/Standard_streams) and redirecting to a sequence of commands that will be written to the output file. To build the program it is necessary to create child processes using [fork()](https://www.geeksforgeeks.org/fork-system-call/) communicating with the parent process through [pipe()](https://www.geeksforgeeks.org/pipe-system-call/), manipulating the environment variable, testing if the command exists or has execution permission, for example, printing errors to [STDERR](https://en.wikipedia.org/wiki/Standard_streams) when necessary, returning the correct [status code](https://www.geeksforgeeks.org/exit-codes-in-c-c-with-examples/).

# Programe
This program takes the infile, outfile to redirect the STDIN (<), STDOUT (>) and 2 commands to pipe. To execute the mandatory program, type the command listed below. The arguments will be processed as same as < infile cmd1 | cmd2 > outfile on the shell.
```
./pipex <infile> <cmd1> <cmd2> <outfile>
```
To execute the bonus program, the project needs to be compiled with the bonus rule before. Then, it takes the infile, outfile to redirect STDIN (<), STDOUT (>) like previous one, but multiple commands can be accepted. The arguments will be process as same as < infile cmd1 | cmd2 | cmd3 ... > outfile on the shell.
```
./pipex <infile> <cmd1> <cmd2> <cmd3> ... <outfile>
```
Only for the bonus program, it supports not only the single angle bracket for the STDOUT (>), but also the double angle bracket for the STDOUT (>>). The single angle bracket will overwite the entire file, but the double angle bracket will append after the file. This can be done by writing the arguments with the index 1 has the here_doc. In this case, the double bracket for the STDIN (<<) will be supported instead of the single bracket for the STDIN (<). That means, infile will be replaced and the lines that a user typed will be written on the STDIN until typing the limiter. When the limiter is typed, the first commands will be executed by taking all of the lines of the STDIN (except the limiter).
```
./pipex here_doc <limiter> <cmd1> <cmd2> <cmd3> ... <outfile>
```

## Comparison of commands pipex vs shell
You can run any command that works in the shell and is in the PATH environment variable as in the examples below:

<table>
	<thead>
		<tr>
			<th colspan=3><h4>Examples (bonus)</h4></th>
		</tr>
		<tr>
			<th>run on</th>
			<th>command</th>
		</tr>
	</thead>
	<tbody>
	</thead>
		<tr>
			<td align="center">pipex</td>
			<td><code>./pipex "input_file" "tr a b" "tr b c" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code>< input_file tr a b | tr b c > output_file</code></td>
		</tr>
		<tr>
			<td><br></td>
		</tr>
		 <tr>
			<td align="center">pipex</td>
			<td><code>./pipex "input_file" "ls -l" "wc -l" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code>< input_file ls -l | wc -l > output_file</code></td>
		</tr>
		<tr>
			<td><br></td>
		</tr>
		 <tr>
			<td align="center">pipex</td>
			<td><code>./pipex "here_doc" "END" "rev" "sort -r" "tr '\n' ' '" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code><< END rev | sort -r | tr '\n' ' ' >> output_file</code></td>
		</tr>
	</tbody>
</table>

## 📝 License

This project is licensed under the MIT - see the [LICENSE](LICENSE) file for details.

---
