```mermaid
graph TD;
	Start(Printf)-->If0{Is format NULL?}
	If0-->|Yes|Return0(Return -1)
	If0-->|No|While0{Go through format}
```
