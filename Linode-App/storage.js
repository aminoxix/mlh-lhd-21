import Storage from 'react-native-storage'

import { settings } from './static'

const storage = new Storage({
  size: 8,
  storageBackend: settings.storageBackend,
  defaultExpires: null,
  enableCache: true,
  sync: {
    // we'll talk about the details later.
  }
})

function getToken(that) {
  storage.load({
    key: 'token',
    autoSync: false,
  }).then(token => {
    that.setState({'token': token})
  }).catch(err => {
    that.setState({'token': `Error getting token!\n${err.message}`})
  })
}

function getPromo(that) {
  storage.load({
    key: 'hasPromo',
    autoSync: false,
  }).then(state => {
    that.setState({'hasPromotion': state})
  }).catch(err => {
    that.setState({'hasPromotion': `Error getting token!\n${err.message}`})
  })
}

export default storage
export { getToken, getPromo }
