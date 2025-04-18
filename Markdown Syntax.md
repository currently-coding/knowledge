
## Callouts
>[!Definition] Callout
>Callouts highlight sections in your Notes
### Syntax
```
>[!<Identifier] <Name>
><Content>
```
#### Foldable Callouts
```
>[!<Identifier]<foldability> <Name>
><Content>
```
- `+` declares *unfolded* the default
- `-` declares *folded* the default
### Styles
- Callouts can have different icons

> [!Unknown]-
> will be used when the provided identifier is unknown

> [!Info]-

>[!Abstract]-
>alias `summary`, `tldr`

>[!Info]-

>[!Todo]-

>[!Tip]-
>alias `hint`, `important`

>[!Success]-
>alias `check`, `done`

>[!Question]-
>alias `help`, `faq`

>[!Warning]-
>alias `caution`, `attention`

>[!Failure]-
>alias `fail`, `missing`

>[!Danger]-
>alias `error`

>[!Bug]-

>[!Example]-

>[!Quote]-
>alias `cite
`
#### Custom Icons
>[!definition]-
>alias `define`, `def`, `let`
