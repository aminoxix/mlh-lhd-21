import Storage from 'react-native-storage'
import { ReloadInstructions } from 'react-native/Libraries/NewAppScreen'

import { settings } from './static'

const storage = new Storage({
  size: 8,
  storageBackend: settings.storageBackend,
  defaultExpires: null,
  enableCache: true,
  /*sync: {
    // we'll talk about the details later.
  }*/
})

export default class LinodeApi {
  constructor() {
    this.base = settings.apiBaseUrl
    this.headers = {
      Authorization: '',
      'User-Agent': 'linode-cli:building',
      'Content-Type': 'application/json',
      'Accept': 'application/json',
    }
    this.account = {}
    this.tokenState = null
  }
  setHeader(token) {
    if (this.headers.Authorization != `Bearer ${token}`) {
      if (token.length == 64) {
        this.headers.Authorization = `Bearer ${token}`
        this.tokenState = true
        return
      }
      this.tokenState = false
    }
  }
  setToken() {
    storage.load({
      key: 'token',
      autoSync: false,
    }).then(token => {
      this.setHeader(token)
    }).catch(err => {
      return err.message
    })
  }
  /*
  get(path) {
    return fetch(`${this.base}${path}`, {
      headers: this.headers
    }).then(res => {return res.json()})
  }
  */
  get(path) {
    return fetch(`${this.base}${path}`, {
      headers: this.headers
    }).then(res => {return res.json()})
  }
  getAccount() {
    let account
    storage.load
    account = this.get('/account')

    return account
  }
}
