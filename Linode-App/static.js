import { StyleSheet } from 'react-native'
import AsyncStorage from '@react-native-community/async-storage'

const settings = {
  apiBaseUrl: 'http://localhost:8080/https://api.linode.com/v4',
  storageBackend: window.localStorage
}
/*
const settings = {
  apiBaseUrl: 'https://api.linode.com/v4',
  storageBackend: AsyncStorage
}
*/

const styles = StyleSheet.create({
  container: {
    justifyContent: 'center',
    backgroundColor: '#333',
    alignItems: 'center',
    flex: 1,
  },
  beeg: {
    justifyContent: 'space-around',
    backgroundColor: '#333',
    alignItems: 'center',
    flex: 1,
  },
  sub: {
    backgroundColor: '#222',
    alignItems: 'center',
    padding: 20,
    margin: 20,
  },
  nav: {
    backgroundColor: 'black',
    borderTopColor: '#222',
    backgroundColor: '#111',
    borderTopWidth: 1,
  },
  inputBox: {
    borderColor: 'gray',
    borderWidth: 1,
    color: 'lime',
    height: 23,
  },
  inputFieldView: {
    justifyContent: 'space-between',
    height: 60,
  },
  refresh: {
    position: 'absolute',
    paddingLeft: 'auto',
    top: 20,
  },
  heading: {
    fontSize: 24,
    color: 'lime',
  },
  heading2: {
    fontSize: 18,
    color: 'lime',
  },
  text: {
    color: 'lime',
  },
  error: {
    color: 'red',
    fontSize: 16,
  },
})

export default styles
export { settings }
