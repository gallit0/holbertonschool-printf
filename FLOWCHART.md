```mermaid
graph TD;
	Start(Printf)-->If0{Is format NULL?}
	If0-->|Yes|Return0(Return -1)
	If0-->|No|While0{Go through format}
	While0-->If1{Is the character '%'<br> and the following<br>NULL or '%'?}
	If1-->|Yes|Put0[Print '%']-->While0
	If1-->|No|If2{Is the character '%'}
	If2-->|Yes|Call0[Call get_function]-->While0
	If2-->|No|Put1[Print character]-->While0
	While0-->|No more characters|Return1(Return counter of chars)
```
